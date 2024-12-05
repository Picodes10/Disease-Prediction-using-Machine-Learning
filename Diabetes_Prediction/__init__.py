from flask import Flask, request, render_template, Blueprint
import pickle
import numpy as np
import os
diabetes_bp = Blueprint('diabetes', __name__, template_folder='templates',
                         static_folder='static'
)

# Initialize Flask app
app = Flask(__name__)

# Load the pre-trained model
model = pickle.load(open(os.path.join(os.path.dirname(__file__), 'model2.pkl'), "rb"))

# Define routes
@diabetes_bp.route('/')
def index():
    return render_template('diabetes.html')

@diabetes_bp.route('/predict', methods=['POST'])
def predict():
    try:
        # Extract user inputs
        features = [float(request.form[feature]) for feature in [
            'Pregnancies', 'Glucose', 'BloodPressure', 'SkinThickness',
            'Insulin', 'BMI', 'DiabetesPedigreeFunction', 'Age'
        ]]
        
        # Model prediction
        prediction = model.predict([features])
        result = "Diabetes Detected" if prediction[0] == 1 else "No Diabetes Detected"
        return render_template('result.html', result=result)
    
    except Exception as e:
        return render_template('result.html', result=f"Error: {str(e)}")

if __name__ == '__main__':
    app.run(debug=True)
