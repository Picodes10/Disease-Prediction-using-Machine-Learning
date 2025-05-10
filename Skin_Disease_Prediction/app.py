from flask import Flask, render_template, request, Blueprint, current_app
from werkzeug.utils import secure_filename
import tensorflow as tf
from tensorflow.keras.preprocessing import image
from tensorflow.keras.models import load_model
import numpy as np
import os
import json

# Initialize Blueprint instead of Flask app
skin_bp = Blueprint('skin', __name__,
                    template_folder=os.path.join(os.path.dirname(os.path.abspath(__file__)), 'templates'),
                    static_folder=os.path.join(os.path.dirname(os.path.abspath(__file__)), 'static'))

# Load model and class mapping
model_path = os.path.dirname(os.path.abspath(__file__))

# Load trained skin disease CNN model
skin_model = load_model(os.path.join(model_path, 'models/skin_model.keras'))

with open(os.path.join(model_path, 'models/skin_class_indices.json')) as f:
    class_indices = json.load(f)

skin_class_labels = {v: k for k, v in class_indices.items()}


def predict_skin_disease(img_path):
    img = image.load_img(img_path, target_size=(224, 224))
    arr = image.img_to_array(img) / 255.0
    arr = np.expand_dims(arr, axis=0)
    preds = skin_model.predict(arr)[0]
    idx = int(np.argmax(preds))
    label = skin_class_labels[idx]
    confidence = round(float(preds[idx]) * 100, 2)
    return label, confidence


disease_info = {
    "Actinic_keratosis": {
        "description": "A rough, scaly patch on the skin caused by years of sun exposure.",
        "precaution": "Use sunscreen daily, wear protective clothing.",
        "recommendation": "Consult a dermatologist for treatment."
    },
    "Atopic_Dermatitis": {
        "description": "Chronic condition causing itchy and inflamed skin.",
        "precaution": "Avoid triggers like allergens and stress.",
        "recommendation": "Apply moisturizers and use prescribed topical steroids."
    },
    "Benign_keratosis": {
        "description": "Non-cancerous skin growths, usually harmless.",
        "precaution": "Avoid scratching or picking.",
        "recommendation": "See a doctor if it changes shape or color."
    },
    "Dermatofibroma": {
        "description": "A benign skin nodule usually resulting from trauma.",
        "precaution": "Avoid irritation or injury.",
        "recommendation": "Surgical removal if painful or bothersome."
    },
    "Melanocytic_nevus": {
        "description": "Common mole formed by melanocytes.",
        "precaution": "Monitor for changes and use sun protection.",
        "recommendation": "Consult dermatologist for abnormal changes."
    },
    "Melanoma": {
        "description": "Dangerous form of skin cancer from melanocytes.",
        "precaution": "Avoid UV rays and monitor moles.",
        "recommendation": "Seek immediate medical intervention."
    },
    "Squamous_cell_carcinoma": {
        "description": "Common skin cancer with red nodules or scaly patches.",
        "precaution": "Use sunscreen, avoid tanning.",
        "recommendation": "Surgical removal or radiation therapy may be needed."
    },
    "Tinea_Ringworm_Candidiasis": {
        "description": "Fungal infection affecting skin, scalp, or nails.",
        "precaution": "Keep skin dry and clean.",
        "recommendation": "Use antifungal creams or powders."
    },
    "Vascular_lesion": {
        "description": "Blood vessel abnormality seen on skin.",
        "precaution": "Avoid trauma to lesion.",
        "recommendation": "Laser or surgery may be advised."
    }
}

friendly_names = {
    "Actinic keratosis": "Precancerous Skin Growth",
    "Atopic Dermatitis": "Eczema",
    "Benign keratosis": "Benign Skin Growth",
    "Dermatofibroma": "Non-cancerous Skin Nodule",
    "Melanocytic nevus": "Mole",
    "Melanoma": "Skin Cancer (Melanoma)",
    "Squamous cell carcinoma": "Skin Cancer (SCC)",
    "Tinea Ringworm Candidiasis": "Fungal Skin Infection",
    "Vascular lesion": "Blood Vessel Lesion"
}


@skin_bp.route('/', methods=['GET', 'POST'])  # Changed from @app.route('/skin-predictor')
def skin_predictor():
    prediction = None
    confidence = None
    filename = None
    details = None
    friendly_name = None

    if request.method == 'POST':
        file = request.files.get('image')
        if file and file.filename:
            filename = secure_filename(file.filename)
            upload_folder = os.path.join(skin_bp.static_folder, 'uploads')
            os.makedirs(upload_folder, exist_ok=True)
            save_path = os.path.join(upload_folder, filename)
            file.save(save_path)

            prediction, confidence = predict_skin_disease(save_path)

            # Normalize prediction key for lookup
            key = prediction.replace(" ", "_").replace("-", "_")
            friendly_name = friendly_names.get(prediction, prediction)
            details = disease_info.get(key, {
                "description": "No description available.",
                "precaution": "N/A",
                "recommendation": "Please consult a dermatologist."
            })

    return render_template('skin-predictor.html',
                           prediction=friendly_name,
                           confidence=confidence,
                           filename=filename,
                           details=details)




