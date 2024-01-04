import json
import tensorflow as tf
from keras import layers
from time import perf_counter_ns
from IPython.display import clear_output
import matplotlib.pyplot as plt

from image import img_b64_to_arr
from shape import shape_to_mask

TRAIN_LENGTH = 238  # info.splits['train'].num_examples
BATCH_SIZE = 16
BUFFER_SIZE = 1000
STEPS_PER_EPOCH = TRAIN_LENGTH // BATCH_SIZE


class Augment(tf.keras.layers.Layer):
    def __init__(self, seed=42):
        super().__init__()
        # both use the same seed, so they'll make the same random changes.
        self.augment_inputs = tf.keras.layers.RandomFlip(mode="horizontal", seed=seed)
        self.augment_labels = tf.keras.layers.RandomFlip(mode="horizontal", seed=seed)

    def call(self, inputs, labels):
        inputs = self.augment_inputs(inputs)
        labels = self.augment_labels(labels)
        return inputs, labels


def display(display_list):
    plt.figure(figsize=(15, 15))

    title = ['Input Image', 'True Mask', 'Predicted Mask']

    for i in range(len(display_list)):
        plt.subplot(1, len(display_list), i + 1)
        plt.title(title[i])
        plt.imshow(display_list[i])
        plt.axis('off')
    plt.show()


def upsample(filters, size, apply_dropout=False):
    initializer = tf.random_normal_initializer(0., 0.02)

    result = tf.keras.Sequential()
    result.add(
        tf.keras.layers.Conv2DTranspose(filters, size, strides=2,
                                        padding='same',
                                        kernel_initializer=initializer,
                                        use_bias=False))

    result.add(tf.keras.layers.BatchNormalization())

    if apply_dropout:
        result.add(tf.keras.layers.Dropout(0.5))

    result.add(tf.keras.layers.ReLU())

    return result


def u_model(output_channels: int):
    base_model = tf.keras.applications.MobileNetV2(input_shape=[128, 128, 3], include_top=False)

    # Use the activations of these layers
    layer_names = [
        'block_1_expand_relu',  # 64x64
        'block_3_expand_relu',  # 32x32
        'block_6_expand_relu',  # 16x16
        'block_13_expand_relu',  # 8x8
        'block_16_project',  # 4x4
    ]
    base_model_outputs = [base_model.get_layer(name).output for name in layer_names]

    # Create the feature extraction model
    down_stack = tf.keras.Model(inputs=base_model.input, outputs=base_model_outputs)

    down_stack.trainable = False

    up_stack = [
        upsample(512, 3),  # 4x4 -> 8x8
        upsample(256, 3),  # 8x8 -> 16x16
        upsample(128, 3),  # 16x16 -> 32x32
        upsample(64, 3),  # 32x32 -> 64x64
    ]

    def unet_model(output_channels: int):
        inputs = tf.keras.layers.Input(shape=[128, 128, 3])

        # Downsampling through the model
        skips = down_stack(inputs)
        x = skips[-1]
        skips = reversed(skips[:-1])

        # Upsampling and establishing the skip connections
        for up, skip in zip(up_stack, skips):
            x = up(x)
            concat = tf.keras.layers.Concatenate()
            x = concat([x, skip])

        # This is the last layer of the model
        last = tf.keras.layers.Conv2DTranspose(
            filters=output_channels, kernel_size=3, strides=2,
            padding='same')  # 64x64 -> 128x128

        x = last(x)

        return tf.keras.Model(inputs=inputs, outputs=x)

    return unet_model(output_channels)


def create_mask(pred_mask):
    pred_mask = tf.argmax(pred_mask, axis=-1)
    pred_mask = pred_mask[..., tf.newaxis]
    return pred_mask[0]


def img_data_to_arr(img_data):
    img_arr = img_b64_to_arr(img_data)
    return img_arr


def normalize(input_image, input_mask):
    input_image = tf.cast(input_image, tf.float32) / 255.0
    input_mask -= 1
    return input_image, input_mask


def json_to_datapoint(json_path):
    file = open(json_path.numpy().decode())
    data = json.load(file)
    width = data['imageWidth']
    height = data['imageHeight']
    mask = None
    for shape in data['shapes']:
        if mask is None:
            mask = shape_to_mask((height, width), shape['points'], shape_type=None, line_width=1, point_size=1)
        else:
            mask = tf.math.logical_or(mask,
                                      shape_to_mask((height, width), shape['points'], shape_type=None, line_width=1,
                                                    point_size=1))
    image = tf.convert_to_tensor(img_data_to_arr(data['imageData']))
    image = layers.Resizing(128, 128)(image)
    mask = tf.convert_to_tensor(mask)
    three_d_mask = tf.expand_dims(mask, axis=-1)
    # four_d_mask = tf.expand_dims(three_d_mask, axis=0)
    mask = layers.Resizing(128, 128)(three_d_mask) > 0.5
    return tf.cast(image, tf.uint8), mask


def get_dataset_partitions_tf(ds, ds_size, train_split=0.8, val_split=0.1, test_split=0.1, shuffle=True,
                              shuffle_size=10000):
    assert (train_split + test_split + val_split) == 1

    if shuffle:
        # Specify seed to always have the same split distribution between runs
        ds = ds.shuffle(shuffle_size, seed=12)

    train_size = int(train_split * ds_size)
    val_size = int(val_split * ds_size)

    train_ds = ds.take(train_size)
    val_ds = ds.skip(train_size).take(val_size)
    test_ds = ds.skip(train_size).skip(val_size)

    return train_ds, val_ds, test_ds


def create_complete_dataset():
    dataset = tf.data.Dataset.list_files("data/SegmDataset/segm/*.json")

    dataset = dataset.map(lambda x: tf.py_function(json_to_datapoint, [x], (tf.uint8, tf.bool)))
    # print(dataset)
    train_ds, val_ds, test_ds = get_dataset_partitions_tf(dataset, len(dataset))

    sample_image, sample_mask = None, None
    for image, mask in train_ds.take(2):
        sample_image, sample_mask = image, mask
        display([image, mask])

    train_batches = (
        train_ds
            .cache()
            .shuffle(BUFFER_SIZE)
            .batch(BATCH_SIZE)
            .repeat()
            # .map(Augment())
            .prefetch(buffer_size=tf.data.AUTOTUNE))

    test_batches = test_ds.batch(BATCH_SIZE)

    OUTPUT_CLASSES = 2

    model = u_model(output_channels=OUTPUT_CLASSES)
    model.compile(optimizer='adam',
                  loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
                  metrics=['accuracy'])

    def show_predictions(dataset=None, num=1):
        if dataset:
            for image, mask in dataset.take(num):
                pred_mask = model.predict(image)
                display([image[0], mask[0], create_mask(pred_mask)])
        else:
            display([sample_image, sample_mask,
                     create_mask(model.predict(sample_image[tf.newaxis, ...]))])

    show_predictions()

    class DisplayCallback(tf.keras.callbacks.Callback):
        def on_epoch_end(self, epoch, logs=None):
            clear_output(wait=True)
            show_predictions()
            print('\nSample Prediction after epoch {}\n'.format(epoch + 1))

    EPOCHS = 25
    VAL_SUBSPLITS = 5
    VALIDATION_STEPS = len(test_ds) // BATCH_SIZE

    model_history = model.fit(train_batches, epochs=EPOCHS,
                              steps_per_epoch=STEPS_PER_EPOCH,
                              validation_steps=VALIDATION_STEPS,
                              validation_data=test_batches,
                              callbacks=[DisplayCallback()], )

    print(model_history.history)
    loss = model_history.history['loss']
    val_loss = model_history.history['val_loss']

    plt.figure()
    plt.plot(model_history.epoch, loss, 'r', label='Training loss')
    plt.plot(model_history.epoch, val_loss, 'bo', label='Validation loss')
    plt.title('Training and Validation Loss')
    plt.xlabel('Epoch')
    plt.ylabel('Loss Value')
    plt.ylim([0, 1])
    plt.legend()
    plt.show()


def load_image(img):
    pass


def ml():
    dataset = {
        'train': [],
        'test': []
    }
    train_images = dataset['train'].map(load_image, num_parallel_calls=tf.data.AUTOTUNE)
    test_images = dataset['test'].map(load_image, num_parallel_calls=tf.data.AUTOTUNE)

    train_batches = (
        train_images
            .cache()
            .shuffle(BUFFER_SIZE)
            .batch(BATCH_SIZE)
            .repeat()
            .map(Augment())
            .prefetch(buffer_size=tf.data.AUTOTUNE))

    test_batches = test_images.batch(BATCH_SIZE)

    for images, masks in train_batches.take(2):
        sample_image, sample_mask = images[0], masks[0]
        display([sample_image, sample_mask])


if __name__ == "__main__":
    tf.config.run_functions_eagerly(True)
    tf.data.experimental.enable_debug_mode()
    # print("Hello World!")
    start = perf_counter_ns()
    # process_image('data/Filip.jpg')
    # ml()
    create_complete_dataset()
    # auto()
    end = perf_counter_ns()
    print("The program took", (end - start) / 1e9, "seconds to run!")
