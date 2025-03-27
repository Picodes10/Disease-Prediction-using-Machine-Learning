from flask import Flask, render_template, request
import pickle
import numpy as np

app = Flask(__name__)

# Load the trained model
with open('model1.pkl', 'rb') as file:
    model = pickle.load(file)

@app.route('/', methods=['GET', 'POST'])
def index():
    prediction = None
    if request.method == 'POST':
        try:
            # Extract input values from the form
            features = [
                float(request.form['mdvp_fo']),
                float(request.form['mdvp_fhi']),
                float(request.form['mdvp_flo']),
                float(request.form['mdvp_jitter']),
                float(request.form['mdvp_shimmer']),
                float(request.form['hnr']),
                float(request.form['rpde']),
                float(request.form['dfa']),
                float(request.form['spread1']),
                float(request.form['spread2'])
            ]
            
            # Convert to NumPy array and reshape
            features_array = np.array(features).reshape(1, -1)
            
            # Make prediction
            prediction = model.predict(features_array)[0]
            prediction = 'Parkinson’s Disease Detected' if prediction == 1 else 'No Parkinson’s Disease'
        except:
            prediction = "Invalid input, please enter valid numbers."
    
    return render_template('parkinsons.html', prediction=prediction)

if __name__ == '__main__':
    app.run(debug=True)
