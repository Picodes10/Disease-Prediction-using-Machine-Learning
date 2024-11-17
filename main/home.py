from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/diabetes')
def diabetes():
    return render_template('diabetes.html')

@app.route('/heart-disease')
def heart_disease():
    return render_template('heart.html')

@app.route('/liver_disease')
def liver_disease():
    return render_template('liver_disease.html')

@app.route('/parkinson')
def parkinson():
    return render_template('parkinsson.html')

@app.route('/stroke_risk')
def stroke_risk():
    return render_template('risk.html')

if __name__ == "__main__":
    app.run(debug=True)
