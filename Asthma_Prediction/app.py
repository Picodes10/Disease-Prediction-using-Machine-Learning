from flask import render_template, request, Blueprint
import pickle
import numpy as np
import os

asthma_bp = Blueprint('asthma', __name__, 
                      template_folder=os.path.join(os.path.dirname(os.path.abspath(__file__)), 'templates'))

# Load the trained model
model_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'asthma_model.pkl')
with open(model_path, 'rb') as file:
    model = pickle.load(file)

@asthma_bp.route('/', methods=['GET', 'POST'])
def index():
    prediction = None
    if request.method == 'POST':
        try:
            # Extract input values from form
            features = [
                float(request.form['age']),
                float(request.form['gender']),               # 0 = Male, 1 = Female
                float(request.form['smoking']),              # 0 = No, 1 = Yes
                float(request.form['dust_exposure']),        # 0 = No, 1 = Yes
                float(request.form['family_history']),       # 0 = No, 1 = Yes
                float(request.form['allergies']),            # 0 = No, 1 = Yes
                float(request.form['fev1']),
                float(request.form['fvc']),
                float(request.form['wheezing']),
                float(request.form['shortness_of_breath']),
                float(request.form['chest_tightness']),
                float(request.form['coughing']),
                float(request.form['nighttime_symptoms']),
                float(request.form['exercise_induced'])
            ]

            # Predict
            features_array = np.array(features).reshape(1, -1)
            result = model.predict(features_array)[0]
            prediction = 'High Risk of Asthma' if result == 1 else 'Low Risk of Asthma'

        except KeyError as e:
            prediction = f"Error: Missing required field - {str(e)}"
        except ValueError as e:
            prediction = f"Error: Invalid input value - {str(e)}"
        except Exception as e:
            prediction = f"Error: {str(e)}"

    return render_template('asthma.html', prediction=prediction)
