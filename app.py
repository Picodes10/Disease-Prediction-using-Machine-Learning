from flask import Flask, render_template, request, jsonify
from Alzhimer_Disease_Prediction.app import alzhimer_bp
from Anemia_Prediction.app import anemia_bp
from Diabetes_Prediction.app import diabetes_bp
from Heart_Disease_Prediction.app import heart_bp
from Liver_Disease_Prediction.app import liver_bp
from Parkinson_Disease.app import parkinsons_bp
from Stroke_Risk_Prediction.app import stroke_bp
from Asthma_Prediction.app import asthma_bp
from PCOS_Prediction.app import pcos_bp
from gembot import chatbot_response
from stress_checker import analyze_stress
import joblib
from werkzeug.utils import secure_filename
from tensorflow.keras.models import load_model
from tensorflow.keras.preprocessing import image
import numpy as np
import os
import json
import requests
import random
from datetime import datetime

def get_youtube_videos(api_key, query="health tips", max_results=3):
    # Add more health-related topics for randomness
    extra_words = [
        "fitness", "mental health", "wellness", "nutrition", "exercise tips",
        "healthy eating", "doctor advice", "immune system", "lifestyle changes",
        "health news", "heart care", "diabetes control", "liver detox",
        "parkinson exercises", "stroke recovery", "alzheimer's prevention"
    ]

    # Combine base query with a random related word
    random_word = random.choice(extra_words)
    full_query =f"{query} {random_word} {datetime.now().minute}"

    url = "https://www.googleapis.com/youtube/v3/search"
    params = {
        "part": "snippet",
        "q": full_query,
        "type": "video",
        "maxResults": max_results,
        "key": api_key
    }

    response = requests.get(url, params=params, timeout=5)
    data = response.json()

    videos = []
    for item in data.get("items", []):
        video_id = item["id"]["videoId"]
        title = item["snippet"]["title"]
        thumbnail = item["snippet"]["thumbnails"]["medium"]["url"]
        videos.append({
            "title": title,
            "video_id": video_id,
            "thumbnail": thumbnail
        })

    return videos

app = Flask(__name__, 
           template_folder='templates',
           static_folder='static')

app.config['UPLOAD_FOLDER'] = 'static/uploads'

# Register blueprints
app.register_blueprint(alzhimer_bp, url_prefix='/alzhimer')
app.register_blueprint(diabetes_bp, url_prefix='/diabetes')
app.register_blueprint(heart_bp, url_prefix='/heart')
app.register_blueprint(liver_bp, url_prefix='/liver')
app.register_blueprint(parkinsons_bp, url_prefix='/parkinsons')
app.register_blueprint(stroke_bp, url_prefix='/stroke')
app.register_blueprint(anemia_bp, url_prefix='/anemia')
app.register_blueprint(asthma_bp, url_prefix='/asthma')
app.register_blueprint(pcos_bp, url_prefix='/pcos')

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/disease-predictor')
def disease_predictor():
    return render_template('disease_selector.html')

@app.route('/stress-checker', methods=['POST'])
def stress_checker():
    answers = request.form.to_dict()
    level, suggestions = analyze_stress(answers)

    return jsonify({
        "level": level,
        "suggestions": suggestions
    })


@app.route('/chatbot')
def chatbot():
    return render_template('chatbot.html')

@app.route('/chatbot', methods=['POST'])
def get_chatbot_response():
    data = request.get_json()
    user_message = data.get('message', '')
    
    if not user_message:
        return jsonify({'response': 'Please provide a question.'})
    
    try:
        response = chatbot_response(user_message)
        return jsonify({'response': response})
    except Exception as e:
        return jsonify({'response': f'Sorry, I encountered an error: {str(e)}'})
    
# Load trained symptom checker model
symptom_model = joblib.load('Symptoms_checker/models/symptom_checker_model.pkl')
symptom_list = joblib.load('Symptoms_checker/models/symptom_list.pkl')
label_encoder = joblib.load('Symptoms_checker/models/label_encoder.pkl')

# Load your cleaned dataset for description/precaution lookups
import pandas as pd
merged_df = pd.read_csv('Symptoms_checker/cleaned_symptom_dataset.csv')

def predict_from_symptoms(user_symptoms):
    vector = [1 if symptom in user_symptoms else 0 for symptom in symptom_list]
    pred_encoded = symptom_model.predict([vector])[0]
    pred_disease = label_encoder.inverse_transform([pred_encoded])[0]
    
    # Fetch description & precautions
    info = merged_df[merged_df['Disease'] == pred_disease].iloc[0]
    return {
        'disease': pred_disease,
        'description': info['Description'],
        'precautions': info['Precautions']
    }

@app.route('/symptom-checker', methods=['GET', 'POST'])
def symptom_checker():
    if request.method == 'POST':
        selected = request.form.getlist('symptoms')
        result = predict_from_symptoms([s.lower() for s in selected])
        return render_template('symptom_result.html', result=result, selected=selected)
    return render_template('symptom_form.html', symptoms=symptom_list)



# Load trained skin disease CNN model
skin_model = load_model('image_scanner/models/skin_model.h5')
# Class labels must match your training folders
with open('image_scanner/models/skin_class_indices.json') as f:
    class_indices = json.load(f)
# Invert to get { index: class_name }
skin_class_labels = {v: k for k, v in class_indices.items()}
def predict_skin_disease(img_path):
    img = image.load_img(img_path, target_size=(224, 224))
    arr = image.img_to_array(img) / 255.0
    arr = np.expand_dims(arr, axis=0)
    preds = skin_model.predict(arr)[0]
    idx = int(np.argmax(preds))

    # lookup the true class name
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



@app.route('/skin-predictor', methods=['GET', 'POST'])
def skin_predictor():
    prediction = None
    confidence = None
    filename = None
    details = None
    friendly_name = None  # Initialize to avoid UnboundLocalError

    if request.method == 'POST':
        file = request.files.get('image')
        if file and file.filename:
            filename = secure_filename(file.filename)
            save_path = os.path.join(app.config['UPLOAD_FOLDER'], filename)
            file.save(save_path)
            prediction, confidence = predict_skin_disease(save_path)

            # Normalize prediction to match dictionary keys
            key = prediction.replace(" ", "_").replace("-", "_")
            friendly_name = friendly_names.get(prediction, prediction)
            details = disease_info.get(key, {
                "description": "No description available.",
                "precaution": "N/A",
                "recommendation": "Please consult a dermatologist."
            })

    return render_template('skin_predictor.html',
                           prediction=friendly_name,
                           confidence=confidence,
                           filename=filename,
                           details=details)

@app.route('/get_health_videos')
def get_health_videos():
    try:
        youtube_api_key = 'AIzaSyA7gKNa7zIdM5m1mHYjoOE3KHBnMA_URFY'  # Replace with your key
        videos = get_youtube_videos(youtube_api_key)
        return jsonify(videos)
    except Exception as e:
        return jsonify({"error":f"Failed to fetch YouTube videos: {str(e)}"})

# Knowledge base page
@app.route('/medibase')
def medibase():

    health_articles = []

    try:
        api_key = '97768cd1094a4c16ab947a080b22660d'  # Replace with your NewsAPI key
        query = 'heart disease OR diabetes OR stroke OR parkinson OR alzheimer OR liver disease OR anemia'
        url = f'https://newsapi.org/v2/everything?q={query}&language=en&sortBy=publishedAt&pageSize=10&apiKey={api_key}'
        response = requests.get(url, timeout=5)
        response.raise_for_status()
        news_data = response.json()
        health_articles = news_data.get('articles', [])
    except requests.exceptions.RequestException as e:
        print(f"News API fetch failed: {e}")
        health_articles = [{"title": "Error", "description": "Unable to fetch health news. Please try again later."}]
    except Exception as e:
        print(f"Unexpected error: {e}")
        health_articles = [{"title": "Error", "description": "Unexpected error occurred. Please try again later."}]

    return render_template('medibase.html', news=health_articles)

@app.route('/credit')
def credit():
    return render_template('credit.html')
    
if __name__ == '__main__':
    app.run(debug=True)
