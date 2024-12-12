from flask import Flask, request, render_template, Blueprint
import pickle
import numpy as np
import os
liver_bp = Blueprint('liver', __name__, template_folder='templates', static_folder='static')

app = Flask(__name__)

# error in loading the model
'''
ValueError: node array from the pickle has an incompatible dtype
'''
#model = pickle.load(open(os.path.join(os.path.dirname(__file__), 'Liver2.pkl'), "rb"))



@liver_bp.route('/')
def index():
    return render_template('liver_disease.html')

@liver_bp.route("/predict", methods=['POST'])
def predict():
    if request.method == 'POST':
        Age = int(request.form['Age'])
        Gender = int(request.form['Gender'])
        Total_Bilirubin = float(request.form['Total_Bilirubin'])
        Alkaline_Phosphotase = int(request.form['Alkaline_Phosphotase'])
        Alamine_Aminotransferase = int(request.form['Alamine_Aminotransferase'])
        Aspartate_Aminotransferase = int(request.form['Aspartate_Aminotransferase'])
        Total_Protiens = float(request.form['Total_Protiens'])
        Albumin = float(request.form['Albumin'])
        Albumin_and_Globulin_Ratio = float(request.form['Albumin_and_Globulin_Ratio'])


        values = np.array([[Age,Gender,Total_Bilirubin,Alkaline_Phosphotase,Alamine_Aminotransferase,Aspartate_Aminotransferase,Total_Protiens,Albumin,Albumin_and_Globulin_Ratio]])
        prediction = model.predict(values)

        return render_template('result.html', prediction=prediction)


if __name__ == "__main__":
    app.run(debug=True)