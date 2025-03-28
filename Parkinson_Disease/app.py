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
            # Extract and print input values
            features = []
            for key in ['mdvp_fo', 'mdvp_fhi', 'mdvp_flo', 'mdvp_jitter', 'mdvp_shimmer', 
                        'hnr', 'rpde', 'dfa', 'spread1', 'spread2']:
                value = request.form.get(key, "").strip()
                print(f"{key}: {value}")  # Debugging line
                
                # Validate input
                if value == "" or not value.replace('.', '', 1).isdigit():
                    raise ValueError(f"Invalid input for {key}: {value}")

                features.append(float(value))

            # Convert to NumPy array and reshape
            features_array = np.array(features).reshape(1, -1)

            # Make prediction
            prediction = model.predict(features_array)[0]
            prediction = 'Parkinson’s Disease Detected' if prediction == 1 else 'No Parkinson’s Disease'
        
        except Exception as e:
            print("Error:", str(e))  # Debugging line
            prediction = "Invalid input, please enter valid numbers."
    
    return render_template('parkinsons.html', prediction=prediction)

if __name__ == '__main__':
    app.run(debug=True)
