from flask import render_template, request, Blueprint
import pickle
import numpy as np
import os

heart_bp = Blueprint('heart', __name__, 
                    template_folder=os.path.join(os.path.dirname(os.path.abspath(__file__)), 'templates'))

# Load the trained heart disease model
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'model.pkl'), 'rb') as file:
    model = pickle.load(file)

@heart_bp.route('/', methods=['GET', 'POST'])
def index():
    prediction = None
    if request.method == 'POST':
        try:
            # Extract input values from the form
            features = [
                float(request.form['age']),
                float(request.form['sex']),
                float(request.form['cp']),
                float(request.form['trestbps']),
                float(request.form['chol']),
                float(request.form['fbs']),
                float(request.form['restecg']),
                float(request.form['thalach']),
                float(request.form['exang']),
                float(request.form['oldpeak']),
                float(request.form['slope']),
                float(request.form['ca']),
                float(request.form['thal'])
            ]
            
            # Convert to NumPy array and reshape
            features_array = np.array(features).reshape(1, -1)
            
            # Make prediction
            prediction = model.predict(features_array)[0]
            prediction = 'High Risk of Heart Disease' if prediction == 1 else 'Low Risk of Heart Disease'
        except KeyError as e:
            prediction = f"Error: Missing required field - {str(e)}"
        except ValueError as e:
            prediction = f"Error: Invalid input value - {str(e)}"
        except Exception as e:
            prediction = f"Error: {str(e)}"
    
    return render_template('heart.html', prediction=prediction)
