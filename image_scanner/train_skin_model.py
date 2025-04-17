import tensorflow as tf
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.applications import MobileNetV2
from tensorflow.keras.models import Model
from tensorflow.keras.layers import Dense, GlobalAveragePooling2D
import os
import json

# Dataset path
DATASET_DIR = "dataset"
IMAGE_SIZE = (224, 224)
BATCH_SIZE = 32
EPOCHS = 5  # You can increase later if needed

# Preprocessing
datagen = ImageDataGenerator(
    rescale=1./255,
    validation_split=0.2
)

# ── Create the training generator ────────────────────────────────────────────
train_generator = datagen.flow_from_directory(
    DATASET_DIR,
    target_size=IMAGE_SIZE,
    batch_size=BATCH_SIZE,
    subset='training'
)

# ── SAVE the mapping from class name → index ─────────────────────────────────
os.makedirs("models", exist_ok=True)               # ensure folder exists
with open("models/skin_class_indices.json", "w") as f:
    json.dump(train_generator.class_indices, f)
print("Saved class_indices mapping:", train_generator.class_indices)
# ─────────────────────────────────────────────────────────────────────────────

# Validation generator
val_generator = datagen.flow_from_directory(
    DATASET_DIR,
    target_size=IMAGE_SIZE,
    batch_size=BATCH_SIZE,
    subset='validation'
)

# Base model
base_model = MobileNetV2(weights='imagenet', include_top=False, input_shape=(224, 224, 3))
base_model.trainable = False

x = base_model.output
x = GlobalAveragePooling2D()(x)
predictions = Dense(len(train_generator.class_indices), activation='softmax')(x)

model = Model(inputs=base_model.input, outputs=predictions)
model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])

# Train!
model.fit(train_generator, validation_data=val_generator, epochs=EPOCHS)

# Save model
model.save("models/skin_model.h5")
print("✅ Model saved at models/skin_model.h5")
