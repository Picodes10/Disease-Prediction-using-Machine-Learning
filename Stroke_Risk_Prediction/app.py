from flask import render_template, request, Blueprint
import joblib
import os
import numpy as np
import pickle

stroke_bp = Blueprint('stroke', __name__, 
                     template_folder=os.path.join(os.path.dirname(os.path.abspath(__file__)), 'templates'))

@stroke_bp.route("/")
def index():
    return render_template("risk.html")

@stroke_bp.route("/result", methods=['POST', 'GET'])
def result():
    try:
        # Extract input values from the form
        gender = int(request.form['gender'])
        age = int(request.form['age'])
        hypertension = int(request.form['hypertension'])
        heart_disease = int(request.form['heart_disease'])
        ever_married = int(request.form['ever_married'])
        work_type = int(request.form['work_type'])
        Residence_type = int(request.form['Residence_type'])
        avg_glucose_level = float(request.form['avg_glucose_level'])
        bmi = float(request.form['bmi'])
        smoking_status = int(request.form['smoking_status'])

        # Create feature array
        features = np.array([
            gender, age, hypertension, heart_disease, ever_married, 
            work_type, Residence_type, avg_glucose_level, bmi, smoking_status
        ]).reshape(1, -1)

        # Load scaler and model using relative paths
        current_dir = os.path.dirname(os.path.abspath(__file__))
        scaler_path = os.path.join(current_dir, 'models', 'scaler.pkl')
        model_path = os.path.join(current_dir, 'models', 'dt.sav')

        # Load and apply scaler
        with open(scaler_path, 'rb') as scaler_file:
            scaler = pickle.load(scaler_file)
        features_scaled = scaler.transform(features)

        # Load and apply model
        model = joblib.load(model_path)
        prediction = model.predict(features_scaled)[0]

        # Return appropriate template based on prediction
        if prediction == 0:
            return render_template('nostroke.html')
        else:
            return render_template('stroke.html')

    except KeyError as e:
        return render_template('risk.html', error=f"Error: Missing required field - {str(e)}")
    except ValueError as e:
        return render_template('risk.html', error=f"Error: Invalid input value - {str(e)}")
    except Exception as e:
        return render_template('risk.html', error=f"Error: {str(e)}")
