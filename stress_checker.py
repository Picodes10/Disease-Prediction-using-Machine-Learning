def analyze_stress(answers):
    score = sum(int(v) for v in answers.values())

    if score <= 4:
        level = "Low"
        tips = ["You're doing great! Keep it up."]
    elif score <= 8:
        level = "Moderate"
        tips = ["Try some mindfulness exercises.", "Take regular breaks."]
    else:
        level = "High"
        tips = ["Consider talking to someone.", "Try meditation and stress-relief techniques."]

    return level, tips
