def analyze_prescription(text):
    text = text.lower()
    analysis = []
    recommendations = []

    if "diabetes" in text or "blood sugar" in text:
        analysis.append("Potential Diabetes Symptoms Detected.")
        recommendations.append("Schedule an HbA1c test and consult an endocrinologist.")

    if "bp" in text or "hypertension" in text:
        analysis.append("Possible signs of Hypertension.")
        recommendations.append("Recommend monitoring blood pressure regularly.")

    if not analysis:
        analysis.append("No critical issues detected.")
        recommendations.append("Continue routine check-ups and healthy lifestyle.")

    return analysis, recommendations
