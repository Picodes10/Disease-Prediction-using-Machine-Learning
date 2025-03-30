from flask import Flask, render_template, request
import pickle
import numpy as np

app = Flask(__name__)

# Load the trained model and scaler
with open('model3.pkl', 'rb') as file:
    model = pickle.load(file)

with open('scaler.pkl', 'rb') as file:
    scaler = pickle.load(file)

@app.route('/', methods=['GET', 'POST'])
def index():
    prediction = None
    
    if request.method == 'POST':
        try:
            # Extract input values from the form
            age = float(request.form['age'])
gender = request.form['gender'].strip().lower()  # Handle case sensitivity
# Convert gender to numerical value
gender = 0 if gender == 'male' else 1 
            total_bilirubin = float(request.form['total_bilirubin'])
            direct_bilirubin = float(request.form['direct_bilirubin'])
            alkaline_phosphotase = float(request.form['alkaline_phosphotase'])
            alamine_aminotransferase = float(request.form['alamine_aminotransferase'])
            aspartate_aminotransferase = float(request.form['aspartate_aminotransferase'])
            total_proteins = float(request.form['total_proteins'])
            albumin = float(request.form['albumin'])
            albumin_globulin_ratio = float(request.form['albumin_globulin_ratio'])


            # Create feature array
            features = np.array([
                age, gender, total_bilirubin, direct_bilirubin,
                alkaline_phosphotase, alamine_aminotransferase,
                aspartate_aminotransferase, total_proteins,
                albumin, albumin_globulin_ratio
            ]).reshape(1, -1)

            # Apply Scaling
            features_scaled = scaler.transform(features)

            # Make prediction
            pred = model.predict(features_scaled)[0]
            prediction = 'Liver Disease Detected' if pred == 1 else 'No Liver Disease'

        except Exception as e:
            prediction = f"Invalid input, please enter valid numbers. Error: {e}"
    
    return render_template('liver.html', prediction=prediction)

if __name__ == '__main__':
    app.run(debug=True)
