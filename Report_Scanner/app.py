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
        if hb < 8:
            analysis.append(f"🩸 Hemoglobin level is **{hb} g/dL**, which is **severely low**. "
                          "This indicates severe anemia that requires immediate medical attention. "
                          "Possible causes include severe blood loss, bone marrow problems, or chronic diseases.")
            diagnosis.append("Severe Anemia - Requires Immediate Medical Attention")
        elif 8 <= hb < 12:
            analysis.append(f"🩸 Hemoglobin level is **{hb} g/dL**, which is **moderately low**. "
                          "This indicates moderate anemia. Common causes include: "
                          "\n- Iron deficiency\n- Vitamin B12 or folate deficiency\n- Chronic kidney disease"
                          "\n- Inflammatory conditions")
            diagnosis.append("Moderate Anemia - Further Investigation Required")
        elif 12 <= hb <= 16:
            analysis.append(f"🩸 Hemoglobin level is **{hb} g/dL**, which is within the **normal range** (12–16 g/dL).")
        elif 16 < hb <= 18:
            analysis.append(f"🩸 Hemoglobin level is **{hb} g/dL**, which is **slightly elevated**. "
                          "This could be due to:\n- Living at high altitude\n- Smoking\n- Dehydration")
            diagnosis.append("Mild Erythrocytosis - Monitor and Evaluate Lifestyle Factors")
        else:
            analysis.append(f"🩸 Hemoglobin level is **{hb} g/dL**, which is **significantly elevated**. "
                          "This could indicate:\n- Polycythemia Vera\n- Chronic lung disease\n- Heart disease"
                          "\n- Sleep apnea")
            diagnosis.append("Secondary Polycythemia or Polycythemia Vera - Requires Hematology Consultation")

    # Glucose Analysis
    glucose_match = re.search(r'(glucose|sugar)[^\d]*(\d+)', text, re.IGNORECASE)
    if glucose_match:
        glucose = int(glucose_match.group(2))
        if glucose > 300:
            analysis.append(f"🍬 Blood glucose is **{glucose} mg/dL**, which is **dangerously high**. "
                          "This indicates severe hyperglycemia and requires immediate medical attention. "
                          "Risk of diabetic ketoacidosis or hyperosmolar hyperglycemic state.")
            diagnosis.append("Severe Hyperglycemia - Possible Diabetic Emergency")
        elif 200 < glucose <= 300:
            analysis.append(f"🍬 Blood glucose is **{glucose} mg/dL**, which is **significantly elevated**. "
                          "This strongly suggests diabetes mellitus. Complications may include:"
                          "\n- Cardiovascular disease\n- Kidney damage\n- Nerve damage\n- Vision problems")
            diagnosis.append("Uncontrolled Diabetes Mellitus - Requires Medical Management")
        elif 140 < glucose <= 200:
            analysis.append(f"🍬 Blood glucose is **{glucose} mg/dL**, which is **moderately elevated**. "
                          "This could indicate:\n- Pre-diabetes\n- Early diabetes\n- Stress hyperglycemia"
                          "\n- Medication effects")
            diagnosis.append("Pre-diabetes or Early Type 2 Diabetes - Lifestyle Modification Recommended")
        elif 70 <= glucose <= 140:
            analysis.append(f"🍬 Blood glucose is **{glucose} mg/dL**, which is within the **normal range** (70-140 mg/dL).")
        elif 50 <= glucose < 70:
            analysis.append(f"🍬 Blood glucose is **{glucose} mg/dL**, which is **low**. "
                          "This mild hypoglycemia could be due to:\n- Prolonged fasting\n- Exercise"
                          "\n- Medication effects\n- Reactive hypoglycemia")
            diagnosis.append("Mild Hypoglycemia - Monitor and Adjust Diet/Medication")
        else:
            analysis.append(f"🍬 Blood glucose is **{glucose} mg/dL**, which is **critically low**. "
                          "Severe hypoglycemia can lead to confusion, seizures, or loss of consciousness. "
                          "Immediate sugar intake and medical attention required.")
            diagnosis.append("Severe Hypoglycemia - Medical Emergency")

    # Blood Pressure Analysis
    bp_match = re.search(r'(\d{2,3})/(\d{2,3})', text)
    if bp_match:
        sys = int(bp_match.group(1))
        dia = int(bp_match.group(2))
        if sys >= 180 or dia >= 120:
            analysis.append(f"🩺 Blood Pressure is **{sys}/{dia} mmHg**, indicating **hypertensive crisis**. "
                          "This is a medical emergency that can lead to:"
                          "\n- Stroke\n- Heart attack\n- Kidney damage\n- Vision loss")
            diagnosis.append("Hypertensive Crisis - Immediate Medical Attention Required")
        elif 160 <= sys < 180 or 100 <= dia < 120:
            analysis.append(f"🩺 Blood Pressure is **{sys}/{dia} mmHg**, indicating **Stage 2 Hypertension**. "
                          "High risk of cardiovascular complications. Requires medication and lifestyle changes.")
            diagnosis.append("Stage 2 Hypertension - Medical Management Required")
        elif 140 <= sys < 160 or 90 <= dia < 100:
            analysis.append(f"🩺 Blood Pressure is **{sys}/{dia} mmHg**, indicating **Stage 1 Hypertension**. "
                          "Lifestyle modifications recommended:\n- Reduce sodium intake\n- Regular exercise"
                          "\n- Stress management\n- Weight management")
            diagnosis.append("Stage 1 Hypertension - Lifestyle Modification Recommended")
        elif 90 <= sys < 140 and 60 <= dia < 90:
            analysis.append(f"🩺 Blood Pressure is **{sys}/{dia} mmHg**, which is in the **normal range**.")
        elif sys < 90 and dia < 60:
            analysis.append(f"🩺 Blood Pressure is **{sys}/{dia} mmHg**, indicating **significant hypotension**. "
                          "Possible causes:\n- Dehydration\n- Blood loss\n- Heart problems\n- Endocrine disorders"
                          "\n- Severe infection")
            diagnosis.append("Significant Hypotension - Medical Evaluation Required")
        else:
            analysis.append(f"🩺 Blood Pressure is **{sys}/{dia} mmHg**, showing **irregular pattern**. "
                          "This unusual combination requires medical evaluation.")
            diagnosis.append("Irregular Blood Pressure Pattern - Further Investigation Needed")

    # Additional Blood Components Analysis
    wbc_match = re.search(r'(white\s+blood\s+cells?|wbc)[^\d]*(\d+(\.\d+)?)', text, re.IGNORECASE)
    if wbc_match:
        wbc = float(wbc_match.group(2))
        if wbc > 11:
            analysis.append(f"🦠 WBC count is **{wbc} K/µL**, which is **elevated**. "
                          "This could indicate:\n- Active infection\n- Inflammation\n- Leukemia"
                          "\n- Stress response")
            diagnosis.append("Leukocytosis - Requires Further Investigation")
        elif wbc < 4:
            analysis.append(f"🦠 WBC count is **{wbc} K/µL**, which is **low**. "
                          "This could suggest:\n- Bone marrow problems\n- Autoimmune conditions"
                          "\n- Viral infections\n- Certain medications")
            diagnosis.append("Leukopenia - Immune System Evaluation Needed")

    # Add Liver Function Analysis
    alt_match = re.search(r'(alt|alanine aminotransferase)[^\d]*(\d+)', text, re.IGNORECASE)
    if alt_match:
        alt = float(alt_match.group(2))
        if alt > 40:
            analysis.append(f"🔸 ALT level is **{alt} U/L**, which is **elevated**. "
                          "This may indicate:\n- Liver inflammation\n- Viral hepatitis"
                          "\n- Medication-induced liver injury\n- Alcohol-related liver disease")
            diagnosis.append("Elevated Liver Enzymes - Hepatic Evaluation Recommended")
            
    # Add Kidney Function Analysis
    creatinine_match = re.search(r'(creatinine)[^\d]*(\d+(\.\d+)?)', text, re.IGNORECASE)
    if creatinine_match:
        creatinine = float(creatinine_match.group(2))
        if creatinine > 1.2:
            analysis.append(f"🔸 Creatinine level is **{creatinine} mg/dL**, which is **elevated**. "
                          "This may indicate:\n- Kidney dysfunction\n- Dehydration"
                          "\n- Muscle breakdown\n- Chronic kidney disease")
            diagnosis.append("Elevated Creatinine - Renal Function Assessment Needed")

    # Add Thyroid Function Analysis
    tsh_match = re.search(r'(tsh|thyroid stimulating hormone)[^\d]*(\d+(\.\d+)?)', text, re.IGNORECASE)
    if tsh_match:
        tsh = float(tsh_match.group(2))
        if tsh > 4.5:
            analysis.append(f"🔸 TSH level is **{tsh} mIU/L**, which is **elevated**. "
                          "This suggests:\n- Hypothyroidism\n- Thyroid hormone deficiency"
                          "\n- Possible autoimmune thyroiditis")
            diagnosis.append("Elevated TSH - Thyroid Function Evaluation Required")
        elif tsh < 0.4:
            analysis.append(f"🔸 TSH level is **{tsh} mIU/L**, which is **low**. "
                          "This suggests:\n- Hyperthyroidism\n- Overactive thyroid"
                          "\n- Possible Graves' disease")
            diagnosis.append("Low TSH - Thyroid Function Evaluation Required")

    # Add Cholesterol Analysis
    cholesterol_match = re.search(r'(cholesterol|total cholesterol)[^\d]*(\d+)', text, re.IGNORECASE)
    if cholesterol_match:
        cholesterol = float(cholesterol_match.group(2))
        if cholesterol > 200:
            analysis.append(f"🔸 Total Cholesterol is **{cholesterol} mg/dL**, which is **elevated**. "
                          "This increases risk of:\n- Cardiovascular disease\n- Atherosclerosis"
                          "\n- Heart attack\n- Stroke")
            diagnosis.append("Hypercholesterolemia - Lipid Management Required")

    # Add Medication Analysis
    medications = []
    common_meds = ['metformin', 'aspirin', 'lisinopril', 'amlodipine', 'metoprolol', 
                   'omeprazole', 'levothyroxine', 'atorvastatin', 'simvastatin']
    
    for med in common_meds:
        if med in text.lower():
            medications.append(med)
    
    if medications:
        med_analysis = "💊 **Current Medications**:\n"
        for med in medications:
            med_analysis += f"- {med.capitalize()}\n"
        analysis.append(med_analysis)
        
    # Add Drug Interaction Analysis
    if len(medications) > 1:
        analysis.append("⚠️ **Multiple medications detected**. Please consult with healthcare provider about potential drug interactions.")

    # Fallback with more detailed guidance
    if not analysis:
        analysis.append("⚠️ Unable to identify specific medical metrics from the report. "
                       "For accurate analysis, ensure:\n"
                       "1. The image is clear and well-lit\n"
                       "2. Text is properly aligned and readable\n"
                       "3. Report contains standard medical terminology\n"
                       "4. Values are clearly visible with units")
        diagnosis.append("Analysis Limited - Image Quality or Data Format Issues")

    return analysis, diagnosis
