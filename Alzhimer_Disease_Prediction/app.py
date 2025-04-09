from flask import render_template, request, Flask, Blueprint
import joblib
import pickle
import numpy as np
import os

alzhimer_bp = Blueprint('alzhimer', __name__, 
                       template_folder=os.path.join(os.path.dirname(os.path.abspath(__file__)), 'templates'))

# Load the trained Alzheimer's model
model = joblib.load(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'alz.pkl'))

@alzhimer_bp.route('/', methods=['GET', 'POST'])
def index():
    prediction = None
    if request.method == 'POST':
        try:
            # Extract input values from form (only selected features)
            features = [
                float(request.form['Age']),
                float(request.form['FamilyHistoryAlzheimers']),
                float(request.form['Depression']),
                float(request.form['HeadInjury']),
                float(request.form['Hypertension']),
                float(request.form['MMSE']),
                float(request.form['MemoryComplaints']),
                float(request.form['BehavioralProblems']),
                float(request.form['ADL']),
                float(request.form['Confusion']),
                float(request.form['Disorientation']),
                float(request.form['PersonalityChanges']),
                float(request.form['DifficultyCompletingTasks']),
                float(request.form['Forgetfulness']),
            ]
            
            # Convert to NumPy array and reshape
            features_array = np.array(features).reshape(1, -1)
            
            # Make prediction
            prediction = model.predict(features_array)[0]
            prediction = 'High Risk of Alzheimer\'s' if prediction == 1 else 'Low Risk of Alzheimer\'s'
        
        except KeyError as e:
            prediction = f"Error: Missing required field - {str(e)}"
        except ValueError as e:
            prediction = f"Error: Invalid input value - {str(e)}"
        except Exception as e:
            prediction = f"Error: {str(e)}"
    
    return render_template('alzhimer.html', prediction=prediction)
