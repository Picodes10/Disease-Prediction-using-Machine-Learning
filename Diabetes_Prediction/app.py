from flask import render_template, request, Blueprint
import pickle
import numpy as np
import os

diabetes_bp = Blueprint('diabetes', __name__, 
                       template_folder=os.path.join(os.path.dirname(os.path.abspath(__file__)), 'templates'))

# Load the trained model
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'model2.pkl'), 'rb') as file:
    model = pickle.load(file)

@diabetes_bp.route('/', methods=['GET', 'POST'])
def index():
    prediction = None
    if request.method == 'POST':
        try:
            # Extract input values from the form
            features = [
                float(request.form['pregnancies']),
                float(request.form['glucose']),
                float(request.form['blood_pressure']),
                float(request.form['skin_thickness']),
                float(request.form['insulin']),
                float(request.form['bmi']),
                float(request.form['diabetes_pedigree_function']),
                float(request.form['age'])
            ]
            
            # Convert to NumPy array and reshape
            features_array = np.array(features).reshape(1, -1)
            
            # Make prediction
            prediction = model.predict(features_array)[0]
            prediction = 'High Risk of Diabetes' if prediction == 1 else 'Low Risk of Diabetes'
        except KeyError as e:
            prediction = f"Error: Missing required field - {str(e)}"
        except ValueError as e:
            prediction = f"Error: Invalid input value - {str(e)}"
        except Exception as e:
            prediction = f"Error: {str(e)}"
    
    return render_template('diabetes.html', prediction=prediction)
