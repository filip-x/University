import matplotlib.pyplot as plt
from time import perf_counter_ns
import tensorflow as tf

from tensorflow import Tensor
from keras import layers
from keras.models import Sequential

img_height = 250
img_width = 250
batch_size = 16
epochs = 5
classes = ['no', 'yes']


def visualize(ds):
    class_names = ds.class_names
    plt.figure(figsize=(10, 10))
    for images, labels in ds.take(1):
        for i in range(9):
            ax = plt.subplot(3, 3, i + 1)
            plt.imshow(images[i].numpy().astype("float"), cmap=plt.get_cmap('gray'))
            plt.title(class_names[labels[i]])
            plt.axis("off")
    plt.show()


def visualize_training(history):
    acc = history.history['accuracy']
    val_acc = history.history['val_accuracy']

    loss = history.history['loss']
    val_loss = history.history['val_loss']

    epochs_range = range(epochs)

    plt.figure(figsize=(8, 8))
    plt.subplot(1, 2, 1)
    plt.plot(epochs_range, acc, label='Training Accuracy')
    plt.plot(epochs_range, val_acc, label='Validation Accuracy')
    plt.legend(loc='lower right')
    plt.title('Training and Validation Accuracy')

    plt.subplot(1, 2, 2)
    plt.plot(epochs_range, loss, label='Training Loss')
    plt.plot(epochs_range, val_loss, label='Validation Loss')
    plt.legend(loc='upper right')
    plt.title('Training and Validation Loss')
    plt.show()


def process(x: Tensor, y):
    x = layers.Resizing(img_height, img_width)(x)
    x = layers.Rescaling(1 / 255, input_shape=(img_height, img_width, 3))(x)
    cs = tf.constant([[0.2126, 0.7512, 0.0722]])
    x = layers.Dot(axes=(3, 1))([x, cs])
    x = layers.Reshape((img_height, img_width, 1), input_shape=(img_height, img_width))(x)
    m = 4
    if m > 1:
        x = layers.Multiply()([x] * m)
    return x, y


models = [
    lambda num_classes: Sequential([
        # layers.Rescaling(1. / 255, input_shape=(img_height, img_width, 3)),
        Sequential([layers.Conv2D(16, 3, padding='same', activation='relu')] * 10),
        layers.AveragePooling2D((2, 2), 2),
        Sequential([layers.Conv2D(32, 3, padding='same', activation='relu')] * 10),
        layers.AveragePooling2D((2, 2), 2),
        Sequential([layers.Conv2D(64, 3, padding='same', activation='relu')] * 10),
        layers.AveragePooling2D((2, 2), 2),
        layers.Flatten(),
        layers.Dense(128, activation='relu'),
        layers.Dense(num_classes, activation='relu')
    ]),
    lambda num_classes: Sequential([
        # layers.Rescaling(1. / 255, input_shape=(img_height, img_width, 3)),
        Sequential([layers.Conv2D(16, 5, padding='same', activation='relu')] * 15),
        layers.MaxPooling2D((2, 2), 2),
        Sequential([layers.Conv2D(32, 5, padding='same', activation='relu')] * 15),
        layers.MaxPooling2D((2, 2), 2),
        Sequential([layers.Conv2D(64, 5, padding='same', activation='relu')] * 15),
        layers.MaxPooling2D((2, 2), 2),
        layers.MaxPooling2D((2, 2), 2),
        layers.MaxPooling2D((2, 2), 2),
        layers.Flatten(),
        layers.Dense(128, activation='relu'),
        layers.Dense(num_classes, activation='relu')
    ]),
    lambda num_classes: Sequential([
        # layers.Rescaling(1. / 255, input_shape=(img_height, img_width, 3)),
        Sequential([layers.Conv2D(16, 3, padding='same', activation='relu')] * 7),
        layers.AveragePooling2D((2, 2), 2),
        Sequential([layers.Conv2D(32, 3, padding='same', activation='relu')] * 7),
        layers.AveragePooling2D((2, 2), 2),
        Sequential([layers.Conv2D(64, 3, padding='same', activation='relu')] * 7),
        layers.AveragePooling2D((2, 2), 2),
        layers.Flatten(),
        layers.Dense(128, activation='relu'),
        layers.Dense(num_classes, activation='relu')
    ])
]


def ml(file_name):
    start = perf_counter_ns()
    data_dir = "data"

    train_ds = tf.keras.utils.image_dataset_from_directory(
        data_dir,
        validation_split=0.1,
        subset="training",
        seed=123,
        image_size=(img_height, img_width),
        batch_size=batch_size)

    val_ds = tf.keras.utils.image_dataset_from_directory(
        data_dir,
        validation_split=0.1,
        subset="validation",
        seed=123,
        image_size=(img_height, img_width),
        batch_size=batch_size)

    class_names = train_ds.class_names
    train_ds = train_ds.map(process)
    train_ds.class_names = class_names
    val_ds = val_ds.map(process)
    visualize(train_ds)

    train_ds = train_ds.cache().shuffle(1000).prefetch(buffer_size=tf.data.AUTOTUNE)
    val_ds = val_ds.cache().prefetch(buffer_size=tf.data.AUTOTUNE)

    num_classes = len(class_names)

    model = models[0](num_classes)

    model.compile(optimizer='adam',
                  loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
                  metrics=['accuracy'])
    model.build(input_shape=(1, img_height, img_width, 1))
    tf.keras.utils.plot_model(model, to_file="model0.png", show_shapes=True, expand_nested=True)
    history = model.fit(
        train_ds,
        validation_data=val_ds,
        epochs=epochs
    )

    visualize_training(history)
    if file_name:
        model.save('./models/' + file_name)


    end = perf_counter_ns()
    print("The program took", (end - start) / 1e9, "seconds to run!")
    exit(0)


def predict(file_name, img):
    model = tf.keras.models.load_model('./models/' + file_name)
    raw = tf.io.read_file(img)
    image = tf.image.decode_jpeg(raw, channels=3)
    image = tf.expand_dims(image, axis=0)
    image, _ = process(image, None)
    result = model.predict(image)
    result = result[0]
    print(result)
    if result[0] > result[1]:
        print("The image does not contain a visible light source. The algorithm is {}% sure of this. {}% otherwise.".format(result[0], result[1]))
    if result[1] > result[0]:
        print("The image contains a visible light source. The algorithm is {}% sure of this. {}% otherwise.".format(result[1], result[0]))
    else:
        print("Inconclusive. Equal probability of {}%.".format(result[0]))


def show_menu():
    print("== Menu ==")
    print("1. Run training")
    print("2. Predict")
    print("0. Exit")
    print()


def ui():
    while True:
        show_menu()
        # try:
        if True:
            option = int(input("Enter an option from the menu: "))
            if option == 0:
                return
            elif option == 1:
                epoch_count = int(input("Epochs count (-1 for default): "))
                file_name = input("Enter model file name: ")
                if epoch_count > 0:
                    global epochs
                    epochs = epoch_count
                if len(file_name) == 0:
                    file_name = None
                ml(file_name)
            elif option == 2:
                file_name = input("Enter model file name to use for prediction: ")
                img = input("Enter path to image: ")
                predict(file_name, img)
            else:
                raise Exception
        # except Exception as e:
        #     print("Bad input!")
        #     print(e)


if __name__ == "__main__":

    # ml("test")
    ui()

# efficient net b7
# vgg 19 / 16
# inception
