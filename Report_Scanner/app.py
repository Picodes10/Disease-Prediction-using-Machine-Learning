from flask import Blueprint, render_template, request
from werkzeug.utils import secure_filename
from PIL import Image
import pytesseract
import os
import re
from pdf2image import convert_from_path

report_scanner_bp = Blueprint('report_scanner', __name__, template_folder='templates', static_folder='static')
UPLOAD_FOLDER = 'uploads'
report_scanner_bp.config = {}
report_scanner_bp.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER

# Ensure upload directory exists
os.makedirs(UPLOAD_FOLDER, exist_ok=True)

@report_scanner_bp.route('/', methods=['GET', 'POST'])
def index():
    analysis = []
    diagnosis = []

    if request.method == 'POST':
        file = request.files['report']
        if file:
            filename = secure_filename(file.filename)
            file_path = os.path.join(report_scanner_bp.config['UPLOAD_FOLDER'], filename)
            file.save(file_path)

            # Handle image or PDF
            if file.filename.lower().endswith('.pdf'):
                images = convert_from_path(file_path)
                text = ""
                for image in images:
                    text += pytesseract.image_to_string(image)
            else:
                image = Image.open(file_path)
                text = pytesseract.image_to_string(image)

            # Analyze the extracted text
            analysis, diagnosis = analyze_report(text)

    return render_template('report.html', analysis=analysis, diagnosis=diagnosis)

def analyze_report(text):
    analysis = []
    diagnosis = []

    # Hemoglobin Analysis
    hb_match = re.search(r'(hemoglobin|hb)[^\d]*(\d+(\.\d+)?)', text, re.IGNORECASE)
    if hb_match:
        hb = float(hb_match.group(2))
        if hb < 12:
            analysis.append(f"🩸 Hemoglobin level is **{hb} g/dL**, which is considered **low**. "
                            "Low hemoglobin may indicate anemia, often caused by iron deficiency, blood loss, or chronic disease. "
                            "You might experience fatigue, weakness, or shortness of breath.")
            diagnosis.append("Iron-Deficiency Anemia or Chronic Anemia")
        elif hb > 18:
            analysis.append(f"🩸 Hemoglobin level is **{hb} g/dL**, which is **elevated**. "
                            "High levels may result from dehydration, lung disease, or polycythemia vera (a rare blood disorder).")
            diagnosis.append("Possible Polycythemia or Secondary Erythrocytosis")
        else:
            analysis.append(f"🩸 Hemoglobin level is **{hb} g/dL**, which is within the **normal range** (12–18 g/dL).")
    
    # Glucose Analysis
    glucose_match = re.search(r'(glucose|sugar)[^\d]*(\d+)', text, re.IGNORECASE)
    if glucose_match:
        glucose = int(glucose_match.group(2))
        if glucose > 200:
            analysis.append(f"🍬 Blood glucose is **{glucose} mg/dL**, which is **very high**. "
                            "This may indicate **poorly managed diabetes** or acute hyperglycemia. "
                            "Consider consulting a doctor immediately and managing carbohydrate intake.")
            diagnosis.append("Type 2 Diabetes or Hyperglycemia")
        elif glucose > 140:
            analysis.append(f"🍬 Blood glucose is **{glucose} mg/dL**, which is **slightly elevated**. "
                            "This could be pre-diabetes. A re-test after fasting is recommended.")
            diagnosis.append("Pre-Diabetes (Impaired Glucose Tolerance)")
        elif glucose < 70:
            analysis.append(f"🍬 Blood glucose is **{glucose} mg/dL**, which is **low**. "
                            "This may be hypoglycemia and can lead to dizziness, shaking, or fainting. Eat or drink something sugary.")
            diagnosis.append("Possible Hypoglycemia")
        else:
            analysis.append(f"🍬 Blood glucose is **{glucose} mg/dL**, which is **within the healthy range** (70–140 mg/dL).")
    
    # Blood Pressure Analysis
    bp_match = re.search(r'(\\d{2,3})/(\\d{2,3})', text)
    if bp_match:
        sys = int(bp_match.group(1))
        dia = int(bp_match.group(2))
        if sys >= 140 or dia >= 90:
            analysis.append(f"🩺 Blood Pressure is **{sys}/{dia} mmHg**, indicating **hypertension (Stage 1 or 2)**. "
                            "This increases the risk of heart disease, stroke, and kidney issues. "
                            "Consider reducing sodium, managing stress, and regular monitoring.")
            diagnosis.append("Hypertension (High Blood Pressure)")
        elif sys < 90 or dia < 60:
            analysis.append(f"🩺 Blood Pressure is **{sys}/{dia} mmHg**, considered **hypotension (low BP)**. "
                            "If accompanied by dizziness or fainting, consult a physician.")
            diagnosis.append("Hypotension")
        else:
            analysis.append(f"🩺 Blood Pressure is **{sys}/{dia} mmHg**, which is in the **normal range** (90/60 – 120/80).")

    # Fallback
    if not analysis:
        analysis.append("⚠️ Unable to identify specific medical metrics from the report. "
                        "Please ensure the uploaded image or PDF is clear and contains standard blood report values.")
        diagnosis.append("No diagnosis available due to poor OCR or missing data")

    return analysis, diagnosis
