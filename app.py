from flask import Flask, render_template, request, jsonify
from Alzhimer_Disease_Prediction.app import alzhimer_bp
from Diabetes_Prediction.app import diabetes_bp
from Heart_Disease_Prediction.app import heart_bp
from Liver_Disease_Prediction.app import liver_bp
from Parkinson_Disease.app import parkinsons_bp
from Stroke_Risk_Prediction.app import stroke_bp
from Asthma_Prediction.app import asthma_bp
from Anemia_Prediction.app import anemia_bp
from PCOS_Prediction.app import pcos_bp
from gembot import chatbot_response

app = Flask(__name__, 
           template_folder='templates',
           static_folder='static')

# Register blueprints
app.register_blueprint(alzhimer_bp, url_prefix='/alzhimer')
app.register_blueprint(diabetes_bp, url_prefix='/diabetes')
app.register_blueprint(heart_bp, url_prefix='/heart')
app.register_blueprint(liver_bp, url_prefix='/liver')
app.register_blueprint(parkinsons_bp, url_prefix='/parkinsons')
app.register_blueprint(stroke_bp, url_prefix='/stroke')
app.register_blueprint(asthma_bp, url_prefix='/asthma')
app.register_blueprint(anemia_bp, url_prefix='/anemia')
app.register_blueprint(pcos_bp, url_prefix='/pcos')

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/chatbot')
def chatbot():
    return render_template('chatbot.html')

@app.route('/chatbot', methods=['POST'])
def get_chatbot_response():
    data = request.get_json()
    user_message = data.get('message', '')
    
    if not user_message:
        return jsonify({'response': 'Please provide a question.'})
    
    try:
        response = chatbot_response(user_message)
        return jsonify({'response': response})
    except Exception as e:
        return jsonify({'response': f'Sorry, I encountered an error: {str(e)}'})

if __name__ == '__main__':
    app.run(debug=True)
    