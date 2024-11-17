from flask import Flask, request, render_template, Blueprint
import pickle
import numpy as np

liver_bp = Blueprint('liver', __name__, template_folder='templates')

app = Flask(__name__)
model = pickle.load(open(r'C:\Users\DELL\Disease-Prediction-using-Machine-Learning\Liver_Disease_Prediction\Liver2.pkl', 'rb'))

@app.route('/')
def Home():
    return render_template('liver_disease.html')

@app.route("/predict", methods=['POST'])
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