from keras import layers
import tensorflow as tf
from tensorflow import keras, Tensor

img_height = 380
img_width = 380


def process(x: Tensor, y):
    x = layers.Rescaling(1 / 255, input_shape=(img_height, img_width, 3))(x)
    cs = tf.constant([[0.2126, 0.7512, 0.0722]])
    x = layers.Dot(axes=(3, 1))([x, cs])
    x = layers.Reshape((img_height, img_width, 1), input_shape=(img_height, img_width))(x)
    m = 32
    if m > 1:
        x = layers.Multiply()([x] * m)
    return x, y

