from flask import Flask, request, render_template, Blueprint
import pickle
import numpy as np
import os
heart_bp = Blueprint('heart', __name__, template_folder='templates', static_folder='static')

app = Flask(__name__)

# Load the trained model
'''
ValueError: node array from the pickle has an incompatible dtype:
- expected: [('left_child', '<i8'), ('right_child', '<i8'), ('feature', '<i8'), ('threshold', '<f8'), ('impurity', '<f8'), ('n_node_samples', '<i8'), ('weighted_n_node_samples', '<f8')]
- got     : {'names': ['left_child', 'right_child', 'feature', 'threshold', 'impurity', 'n_node_samples', 'weighted_n_node_samples', 'missing_go_to_left'], 'formats': ['<i8', '<i8', '<i8', '<f8', '<f8', '<i8', '<f8', 'u1'], 'offsets': [0, 8, 16, 24, 32, 40, 48, 56], 'itemsize': 64}

please fix the model before loading it
'''
#model = pickle.load(open(os.path.join(os.path.dirname(__file__), 'model.pkl'), "rb"))

# Define the home route
@heart_bp.route("/")
def index():
    return render_template("heart.html")

# Define the prediction route
@heart_bp.route("/predict", methods=["POST"])
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
