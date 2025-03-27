from flask import Flask, render_template, request
import pickle
import sklearn
print(sklearn.__version__)
import numpy as np

app = Flask(__name__)

# Load the trained model
with open('model2.pkl', 'rb') as file:
    model = pickle.load(file)

@app.route('/', methods=['GET', 'POST'])
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
            prediction = 'Diabetic' if prediction == 1 else 'Non-Diabetic'
        except:
            prediction = "Invalid input, please enter valid numbers."
    
    return render_template('diabetes.html', prediction=prediction)

if __name__ == '__main__':
    app.run(debug=True)