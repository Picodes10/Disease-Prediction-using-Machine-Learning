from flask import Flask, render_template, request
import pickle
import joblib
import numpy as np

app = Flask(__name__)

# Load the trained stroke risk model
model = joblib.load('stroke.pkl')

@app.route('/', methods=['GET', 'POST'])
def index():
    prediction = None
    if request.method == 'POST':
        try:
            features = [
                float(request.form['age']),
                float(request.form['hypertension']),
                float(request.form['heart_disease']),
                float(request.form['avg_glucose_level']),
                float(request.form['bmi']),
                float(request.form['smoking_status'])
            ]
            scaler = joblib.load('scaler.pkl')
            features_array = np.array(features).reshape(1, -1)

            prediction = model.predict(features_array)[0]  # ✅ No "NotFittedError" if model is loaded correctly
            prediction = 'High Risk of Stroke' if prediction == 1 else 'Low Risk of Stroke'
        except Exception as e:
            prediction = f"Invalid input: {str(e)}"
    
    return render_template('risk.html', prediction=prediction)

if __name__ == '__main__':
    app.run(debug=True)
    