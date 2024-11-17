from flask import Flask, request, render_template, Blueprint
import pickle
import numpy as np

heart_bp = Blueprint('heart', __name__, template_folder='templates')

app = Flask(__name__)

# Load the trained model
model = pickle.load(open(r'C:\Users\DELL\Disease-Prediction-using-Machine-Learning\Heart_Disease_Prediction\model.pkl', "rb"))

# Define the home route
@app.route("/")
def home():
    return render_template("heart.html")

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
