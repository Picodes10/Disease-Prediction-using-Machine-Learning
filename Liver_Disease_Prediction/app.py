from flask import render_template, request, Blueprint
import pickle
import numpy as np
import os

liver_bp = Blueprint('liver', __name__, 
                    template_folder=os.path.join(os.path.dirname(os.path.abspath(__file__)), 'templates'))

# Load the trained liver disease model and scaler
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'model3.pkl'), 'rb') as file:
    model = pickle.load(file)
    
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'scaler.pkl'), 'rb') as file:
    scaler = pickle.load(file)

@liver_bp.route('/', methods=['GET', 'POST'])
def index():
    prediction = None
    if request.method == 'POST':
        try:
            # Extract and order input values to match training data
            features = [
                float(request.form['age']),
                0 if request.form['gender'].lower() == 'male' else 1,  # Convert gender to 0/1
                float(request.form['total_bilirubin']),
                float(request.form['direct_bilirubin']),
                float(request.form['alkaline_phosphatase']),
                float(request.form['alamine_aminotransferase']),
                float(request.form['aspartate_aminotransferase']),
                float(request.form['total_proteins']),
                float(request.form['albumin']),
                float(request.form['albumin_globulin_ratio'])
            ]
            
            # Convert to NumPy array, reshape and scale
            features_array = np.array(features).reshape(1, -1)
            features_scaled = scaler.transform(features_array)
            
            # Make prediction (model outputs 1 for disease, 0 for no disease)
            prediction = model.predict(features_scaled)[0]
            prediction = 'High Risk of Liver Disease' if prediction == 1 else 'Low Risk of Liver Disease'
        except KeyError as e:
            prediction = f"Error: Missing required field - {str(e)}"
        except ValueError as e:
            prediction = f"Error: Invalid input value - {str(e)}"
        except Exception as e:
            prediction = f"Error: {str(e)}"
    
    return render_template('liver.html', prediction=prediction)
