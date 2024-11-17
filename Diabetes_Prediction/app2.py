from flask import Flask, request, render_template, Blueprint
import pickle
import numpy as np

diabetes_bp = Blueprint('diabetes', __name__, template_folder='templates')

# Initialize Flask app
app = Flask(__name__)

# Load the pre-trained model
with open(r'C:\Users\DELL\Disease-Prediction-using-Machine-Learning\Diabetes_Prediction\model2.pkl', 'rb') as file:
    model = pickle.load(file)

# Define routes
@app.route('/')
def index():
    return render_template('diabetes.html')

@app.route('/predict', methods=['POST'])
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
