
# home.py (main folder)
import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from flask import Flask, render_template
from Diabetes_Prediction import diabetes_bp
from Heart_Disease_Prediction import heart_bp
from Liver_Disease_Prediction import liver_bp
from Parkinson_Disease import parkinson_bp
from Stroke_Risk_Prediction import stroke_bp

app = Flask(__name__)

# Register Blueprints
app.register_blueprint(diabetes_bp, url_prefix='/diabetes')
app.register_blueprint(heart_bp, url_prefix='/heart-disease')
app.register_blueprint(liver_bp, url_prefix='/liver-disease')
app.register_blueprint(parkinson_bp, url_prefix='/parkinson')
app.register_blueprint(stroke_bp, url_prefix='/stroke-risk')




@app.route('/')
def home():
    return render_template('HOME.html')


if __name__ == "__main__":
    app.run(debug=True)
