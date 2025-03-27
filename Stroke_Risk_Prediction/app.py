from flask import Flask, render_template, request
import pickle
import numpy as np

app = Flask(__name__)

# Load the trained model
with open('stroke_model.pkl', 'rb') as file:
    model = pickle.load(file)

@app.route('/', methods=['GET', 'POST'])
def index():
    prediction = None
    if request.method == 'POST':
        try:
            # Extract input values
            features = [
                float(request.form['age']),
                float(request.form['hypertension']),
                float(request.form['heart_disease']),
                float(request.form['avg_glucose_level']),
                float(request.form['bmi'])
                float(request.form['gender']),
                float(request.form['smoking_status']),
                float(request.form['residence_type']),
                float(request.form['work_type']),
                float(request.form['ever_married'])
            ]
            
            print("Received input:", features)  # Debugging line
            
            # Convert to NumPy array
            features_array = np.array(features).reshape(1, -1)

            # Make prediction
            prediction = model.predict(features_array)[0]
            prediction = 'High Risk' if prediction == 1 else 'Low Risk'
        except Exception as e:
            prediction = f"Invalid input: {e}"  # Print the actual error
    
    return render_template('risk.html', prediction=prediction)

if __name__ == '__main__':
    app.run(debug=True)
