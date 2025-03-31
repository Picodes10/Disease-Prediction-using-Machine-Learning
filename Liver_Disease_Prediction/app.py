from flask import render_template, request, Blueprint
import pickle
import numpy as np
import os

liver_bp = Blueprint('liver', __name__, 
                    template_folder=os.path.join(os.path.dirname(os.path.abspath(__file__)), 'templates'))

# Load the trained liver disease model
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'model3.pkl'), 'rb') as file:
    model = pickle.load(file)

@liver_bp.route('/', methods=['GET', 'POST'])
def index():
    prediction = None
    if request.method == 'POST':
        try:
            # Extract input values from the form
            features = [
                float(request.form['age']),
                float(request.form['gender']),
                float(request.form['total_bilirubin']),
                float(request.form['direct_bilirubin']),
                float(request.form['alkaline_phosphatase']),
                float(request.form['alamine_aminotransferase']),
                float(request.form['aspartate_aminotransferase']),
                float(request.form['total_proteins']),
                float(request.form['albumin']),
                float(request.form['albumin_globulin_ratio'])
            ]
            
            # Convert to NumPy array and reshape
            features_array = np.array(features).reshape(1, -1)
            
            # Make prediction
            prediction = model.predict(features_array)[0]
            prediction = 'High Risk of Liver Disease' if prediction == 1 else 'Low Risk of Liver Disease'
        except KeyError as e:
            prediction = f"Error: Missing required field - {str(e)}"
        except ValueError as e:
            prediction = f"Error: Invalid input value - {str(e)}"
        except Exception as e:
            prediction = f"Error: {str(e)}"
    
    return render_template('liver.html', prediction=prediction)
