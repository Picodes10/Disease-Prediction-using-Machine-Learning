from flask import Flask, request, render_template
import pickle
import numpy as np

app = Flask(__name__)

# Load the trained model
model = pickle.load(open("model.pkl", "rb"))

# Define the home route
@app.route("/")
def home():
    return render_template("index.html")

# Define the prediction route
@app.route("/predict", methods=["POST"])
def predict():
    # Extract input features from the form
    try:
        input_features = [
            float(request.form.get(feature)) 
            for feature in ['age', 'sex', 'cp', 'trestbps', 'chol', 'fbs', 'restecg', 'thalach', 'exang', 'oldpeak', 'slope', 'ca', 'thal']
        ]
        # Predict using the model
        prediction = model.predict([input_features])
        result = "Heart Disease Detected" if prediction[0] == 1 else "No Heart Disease"
        return render_template("result.html", prediction=result)
    except Exception as e:
        return f"Error occurred: {str(e)}"

if __name__ == "__main__":
    app.run(debug=True)
