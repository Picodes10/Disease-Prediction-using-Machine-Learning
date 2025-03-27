from flask import Flask, render_template, request
import pickle
import numpy as np

app = Flask(__name__)

# Load the trained model
with open('model3.pkl', 'rb') as file:
    model = pickle.load(file)

@app.route('/', methods=['GET', 'POST'])
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
                float(request.form['alkaline_phosphotase']),
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
            prediction = 'Liver Disease Detected' if prediction == 1 else 'No Liver Disease'
        except:
            prediction = "Invalid input, please enter valid numbers."
    
    return render_template('liver.html', prediction=prediction)

if __name__ == '__main__':
    app.run(debug=True)
