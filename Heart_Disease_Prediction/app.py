from flask import Flask, render_template, request
import pickle
import numpy as np

app = Flask(__name__)

# Load the trained heart disease model
with open('model.pkl', 'rb') as file:
    model = pickle.load(file)

@app.route('/', methods=['GET', 'POST'])
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
        except:
            prediction = "Invalid input, please enter valid numbers."
    
    return render_template('heart.html', prediction=prediction)

if __name__ == '__main__':
    app.run(debug=True)