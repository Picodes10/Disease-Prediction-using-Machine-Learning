from flask import render_template, request, Blueprint
import pickle
import numpy as np
import os

parkinsons_bp = Blueprint('parkinsons', __name__, 
                         template_folder=os.path.join(os.path.dirname(os.path.abspath(__file__)), 'templates'))

# Load the trained model and scaler
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'model1.pkl'), 'rb') as file:
    model = pickle.load(file)

with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'scaler.pkl'), 'rb') as file:
    scaler = pickle.load(file)

@parkinsons_bp.route('/', methods=['GET', 'POST'])
def index():
    prediction = None
    if request.method == 'POST':
        try:
            # Define all required features
            feature_keys = [
                'mdvp_fo', 'mdvp_fhi', 'mdvp_flo', 'mdvp_jitter',
                'mdvp_jitter_abs', 'mdvp_rap', 'mdvp_ppq', 'jitter_ddp',
                'mdvp_shimmer', 'mdvp_shimmer_db', 'shimmer_apq3',
                'shimmer_apq5', 'mdvp_apq', 'shimmer_dda', 'nhr',
                'hnr', 'rpde', 'dfa', 'spread1', 'spread2', 'd2', 'ppe'
            ]
            
            # Extract and validate input values
            features = []
            for key in feature_keys:
                value = request.form.get(key, "").strip()
                if value == "" or not value.replace('.', '', 1).isdigit():
                    raise ValueError(f"Invalid input for {key}: {value}")
                features.append(float(value))
            
            # Create feature array and apply scaling
            features_array = np.array(features).reshape(1, -1)
            features_scaled = scaler.transform(features_array)
            
            # Make prediction
            prediction = model.predict(features_scaled)[0]
            prediction = 'High Risk of Parkinson\'s Disease' if prediction == 1 else 'Low Risk of Parkinson\'s Disease'
            
        except KeyError as e:
            prediction = f"Error: Missing required field - {str(e)}"
        except ValueError as e:
            prediction = f"Error: Invalid input value - {str(e)}"
        except Exception as e:
            prediction = f"Error: {str(e)}"
    
    return render_template('parkinsons.html', prediction=prediction)
