def eff():
    data_dir = "data/Dataset"
    batch_size = 16

    train_ds = tf.keras.utils.image_dataset_from_directory(
        data_dir,
        label_mode='categorical',
        validation_split=0.1,
        subset="training",
        seed=124,
        image_size=(img_height, img_width),
        batch_size=batch_size)

    val_ds = tf.keras.utils.image_dataset_from_directory(
        data_dir,
        label_mode='categorical',
        validation_split=0.1,
        subset="validation",
        seed=124,
        image_size=(img_height, img_width),
        batch_size=batch_size)

    # visualize(train_ds)
    class_names = train_ds.class_names
    # train_ds = train_ds.map(process)
    # train_ds = train_ds.map(lambda x, y: (layers.Multiply()([x, x, x, x, x]), y))
    train_ds.class_names = class_names
    # val_ds = val_ds.map(process)
    # visualize(train_ds)
    # return

    # train_ds = train_ds.map(lambda x, y: (process_image(x), y))
    # visualize(train_ds)
    # performance setting apparently
    AUTOTUNE = tf.data.AUTOTUNE
    train_ds = train_ds.cache().shuffle(1000).prefetch(buffer_size=AUTOTUNE)
    val_ds = val_ds.cache().prefetch(buffer_size=AUTOTUNE)

    num_classes = len(class_names)
    inputs = layers.Input(shape=(img_height, img_width, 3))
    # x = img_augmentation(inputs)
    outputs = EfficientNetB4(include_top=True, weights=None, classes=num_classes)(inputs)

    model = tf.keras.Model(inputs, outputs)
    model.compile(
        optimizer="adam", loss="categorical_crossentropy", metrics=["accuracy"]
    )

    model.summary()

    epochs = 40  # @param {type: "slider", min:10, max:100}
    hist = model.fit(train_ds, epochs=epochs, validation_data=val_ds, verbose=2)


    epochs = 100
    visualize_training(hist, epochs)

def process_image(img):
    if isinstance(img, str):
        img = Image.open(img)
    # Import background image
    # background_img_raw = img.convert('RGB')  # RGBA image
    background_img = rgb2lum(tf.make_ndarray())  # Inputs to blend_modes need to be numpy arrays.
    background_img = Image.fromarray(background_img).convert('RGBA')
    background_img = np.array(background_img)
    background_img_float = background_img.astype(float)  # Inputs to blend_modes need to be floats.

    # Import foreground image
    # foreground_img_raw = img.convert('RGB')  # RGBA image
    foreground_img = rgb2lum(img.numpy())  # Inputs to blend_modes need to be numpy arrays.
    foreground_img = Image.fromarray(foreground_img).convert('RGBA')
    foreground_img = np.array(foreground_img)
    foreground_img_float = foreground_img.astype(float)  # Inputs to blend_modes need to be floats.

    # Blend images
    opacity = 1  # The opacity of the foreground that is blended onto the background is 70 %.
    blended_img_float = blend_modes.multiply(background_img_float, foreground_img_float, opacity)
    for i in range(4):
        blended_img_float = blend_modes.multiply(blended_img_float, foreground_img_float, opacity)

    # Convert blended image back into PIL image
    blended_img = np.uint8(blended_img_float)  # Image needs to be converted back to uint8 type for PIL handling.
    blended_img_raw = Image.fromarray(blended_img)  # Note that alpha channels are displayed in black by PIL by default.
    # This behavior is difficult to change (although possible).
    # If you have alpha channels in your images, then you should give
    # OpenCV a try.

    # Display blended image
    # display(blended_img_raw)
    # display(blended_img_raw)

    return blended_img_raw