from flask import render_template, request, Blueprint
import pickle
import numpy as np
import os
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier

parkinsons_bp = Blueprint('parkinsons', __name__, 
                         template_folder=os.path.join(os.path.dirname(os.path.abspath(__file__)), 'templates'))

# Define the 10 required features
required_features = [
    'MDVP:Fo(Hz)',
    'MDVP:Fhi(Hz)',
    'MDVP:Flo(Hz)',
    'MDVP:Jitter(%)',
    'MDVP:Shimmer',
    'HNR',
    'RPDE',
    'DFA',
    'spread1',
    'spread2'
]

# Load and preprocess data
df = pd.read_csv(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'parkinsson.csv'))
X = df[required_features]
y = df['status']

# Train new scaler and model
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

model = RandomForestClassifier(n_estimators=100, random_state=42)
model.fit(X_scaled, y)

# Save the new model and scaler
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'model1.pkl'), 'wb') as file:
    pickle.dump(model, file)

with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'scaler.pkl'), 'wb') as file:
    pickle.dump(scaler, file)

@parkinsons_bp.route('/', methods=['GET', 'POST'])
def index():
    prediction = None
    if request.method == 'POST':
        try:
            # Define the 10 required features for the model
            feature_keys = [
                'mdvp_fo',    # MDVP:Fo(Hz)
                'mdvp_fhi',   # MDVP:Fhi(Hz) 
                'mdvp_flo',   # MDVP:Flo(Hz)
                'mdvp_jitter', # MDVP:Jitter(%)
                'mdvp_shimmer', # MDVP:Shimmer
                'hnr',        # HNR
                'rpde',       # RPDE
                'dfa',        # DFA
                'spread1',    # spread1
                'spread2'     # spread2
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
