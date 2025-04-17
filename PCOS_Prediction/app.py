from flask import render_template, request, Blueprint
import joblib
import numpy as np
import os

# Define the PCOS blueprint
pcos_bp = Blueprint('pcos', __name__,
                    template_folder=os.path.join(os.path.dirname(os.path.abspath(__file__)), 'templates'))

# Load the trained model and scaler
model_path = os.path.dirname(os.path.abspath(__file__))
with open(os.path.join(model_path, 'pcos_model.pkl'), 'rb') as file:
    model = joblib.load(file)

with open(os.path.join(model_path, 'pcos_scaler.pkl'), 'rb') as file:
    scaler = joblib.load(file)

@pcos_bp.route('/', methods=['GET', 'POST'])
def index():
    prediction = None
    if request.method == 'POST':
        try:
            # Get form inputs
            features = [
                float(request.form['age']),
                float(request.form['bmi']),
                float(request.form['menstrual_irregularity']),
                float(request.form['testosterone_level']),
                float(request.form['antral_follicle_count'])
            ]

            # Scale features
            scaled_features = scaler.transform([features])

            # Predict
            result = model.predict(scaled_features)[0]
            prediction = 'High Risk of PCOS' if result == 1 else 'Low Risk of PCOS'

        except KeyError as e:
            prediction = f"Error: Missing required field - {str(e)}"
        except ValueError as e:
            prediction = f"Error: Invalid input value - {str(e)}"
        except Exception as e:
            prediction = f"Error: {str(e)}"

    return render_template('pcos.html', prediction=prediction)
