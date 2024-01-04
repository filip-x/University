import matplotlib.pyplot as plt
import numpy as np
from time import perf_counter_ns
import tensorflow as tf

print(tf.__version__)

from keras import layers
from keras.models import Sequential

from keras.layers.normalization.layer_normalization import *
from keras.layers.normalization.batch_normalization import *

ak = None
img_height = 380
img_width = 380


def rgb2lum(rgb):
    return np.dot(rgb[..., :3], [0.2126, 0.7512, 0.0722])


def display(img):
    plt.imshow(img)
    plt.axis('off')
    plt.show()


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


def visualize_training(history, epochs):
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


def converter(x):
    # x has shape (batch, width, height, channels)
    return (0.21 * x[:, :, :, :1]) + (0.75 * x[:, :, :, 1:2]) + (0.07 * x[:, :, :, -1:])


def process(x, y):
    x = layers.Rescaling(1 / 255, input_shape=(img_height, img_width, 3))(x)
    cs = tf.constant([[0.2126, 0.7512, 0.0722]])
    # x = layers.Lambda(converter)(x)
    x = layers.Dot(axes=(3, 1))([x, cs])
    x = layers.Reshape((img_height, img_width, 1), input_shape=(img_height, img_width))(x)
    # x = layers.Rescaling(255, input_shape=(img_height, img_width, 1))(x)
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
]


def ml():
    data_dir = "data/Dataset"
    batch_size = 16

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

    # visualize(train_ds)
    class_names = train_ds.class_names
    train_ds = train_ds.map(process)
    # # train_ds = train_ds.map(lambda x, y: (layers.Multiply()([x, x, x, x, x]), y))
    train_ds.class_names = class_names
    val_ds = val_ds.map(process)
    visualize(train_ds)
    # return
    # return

    # train_ds = train_ds.map(lambda x, y: (process_image(x), y))
    # visualize(train_ds)
    # performance setting apparently
    AUTOTUNE = tf.data.AUTOTUNE
    train_ds = train_ds.cache().shuffle(1000).prefetch(buffer_size=AUTOTUNE)
    val_ds = val_ds.cache().prefetch(buffer_size=AUTOTUNE)

    num_classes = len(class_names)

    model = models[0](num_classes)
    # model = Sequential([
    #     # layers.Rescaling(1. / 255, input_shape=(img_height, img_width, 3)),
    #     Sequential([layers.Conv2D(16, 3, padding='same', activation='relu')] * 10),
    #     layers.AveragePooling2D((2, 2), 2),
    #     Sequential([layers.Conv2D(32, 3, padding='same', activation='relu')] * 10),
    #     layers.AveragePooling2D((2, 2), 2),
    #     Sequential([layers.Conv2D(64, 3, padding='same', activation='relu')] * 10),
    #     layers.AveragePooling2D((2, 2), 2),
    #     layers.Flatten(),
    #     layers.Dense(128, activation='relu'),
    #     layers.Dense(num_classes, activation='relu')
    # ])

    model.compile(optimizer='adam',
                  loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
                  metrics=['accuracy'])

    epochs = 25
    history = model.fit(
        train_ds,
        validation_data=val_ds,
        epochs=epochs
    )

    visualize_training(history, epochs)


def auto():
    data_dir = "data/Dataset"
    batch_size = 16

    train_ds = tf.keras.utils.image_dataset_from_directory(
        data_dir,
        validation_split=0.1,
        subset="training",
        seed=124,
        image_size=(img_height, img_width),
        batch_size=batch_size)

    val_ds = tf.keras.utils.image_dataset_from_directory(
        data_dir,
        validation_split=0.1,
        subset="validation",
        seed=124,
        image_size=(img_height, img_width),
        batch_size=batch_size)

    # visualize(train_ds)
    class_names = train_ds.class_names
    train_ds = train_ds.map(process)
    # train_ds = train_ds.map(lambda x, y: (layers.Multiply()([x, x, x, x, x]), y))
    train_ds.class_names = class_names
    val_ds = val_ds.map(process)
    visualize(train_ds)
    # return

    # train_ds = train_ds.map(lambda x, y: (process_image(x), y))
    # visualize(train_ds)
    # performance setting apparently
    AUTOTUNE = tf.data.AUTOTUNE
    train_ds = train_ds.cache().shuffle(1000).prefetch(buffer_size=AUTOTUNE)
    val_ds = val_ds.cache().prefetch(buffer_size=AUTOTUNE)

    # Initialize the image classifier.
    clf = ak.ImageClassifier(overwrite=True, max_trials=1)
    # Feed the image classifier with training data.
    history = clf.fit(train_ds, validation_data=val_ds)


if __name__ == "__main__":
    # tf.config.run_functions_eagerly(True)
    # print("Hello World!")
    start = perf_counter_ns()
    # process_image('data/Filip.jpg')
    ml()
    # auto()
    end = perf_counter_ns()
    print("The program took", (end - start) / 1e9, "seconds to run!")

# efficient net b7
# vgg 19 / 16
# inception
