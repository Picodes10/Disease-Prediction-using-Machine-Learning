from flask import render_template, request, Blueprint
import joblib
import numpy as np
import os

# Setup blueprint
anemia_bp = Blueprint('anemia', __name__, 
                      template_folder=os.path.join(os.path.dirname(os.path.abspath(__file__)), 'templates'))

# Load model, scaler, encoder
model_path = os.path.dirname(os.path.abspath(__file__))
model = joblib.load(os.path.join(model_path, 'models/anemia_model.pkl'))
scaler = joblib.load(os.path.join(model_path, 'models/anemia_scaler.pkl'))
label_encoder = joblib.load(os.path.join(model_path, 'models/anemia_label_encoder.pkl'))

@anemia_bp.route('/', methods=['GET', 'POST'])
def index():
    prediction = None
    if request.method == 'POST':
        try:
            # Get input values from form
            gender = request.form['gender'].capitalize()
            hemoglobin = float(request.form['hemoglobin'])
            mchc = float(request.form['mchc'])
            mcv = float(request.form['mcv'])
            mch = float(request.form['mch'])

            # Encode gender: Male -> 0, Female -> 1
            gender_encoded = 0 if gender == 'Male' else 1

            # Combine features
            features = np.array([[gender_encoded, hemoglobin, mchc, mcv, mch]])
            features_scaled = scaler.transform(features)

            # Predict
            result_encoded = model.predict(features_scaled)[0]
            label = label_encoder.inverse_transform([result_encoded])[0]
            prediction = "High Risk of Anemia" if label.lower() == 'anemia' else "Normal"

        except KeyError as e:
            prediction = f"Error: Missing required field - {str(e)}"
        except ValueError as e:
            prediction = f"Error: Invalid input value - {str(e)}"
        except Exception as e:
            prediction = f"Error: {str(e)}"

    return render_template('anemia.html', prediction=prediction)
