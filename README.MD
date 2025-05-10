# 🧠 Human Disease Prediction System using Machine Learning

A comprehensive AI-powered health application built using **Flask**, integrating multiple disease prediction modules, a symptom checker, stress analyzer, chatbot assistant, and wellness features like **YouTube health tips** and **News API-powered Medibase**.

---

## 🚀 Features

- 🔬 Predicts the likelihood of multiple diseases:
  - Alzheimer’s
  - Diabetes
  - Heart Disease
  - Liver Disease
  - Parkinson’s
  - Stroke
  - Anemia
  - Asthma
  - PCOS
  - Skin Disease Detection
- 🩺 **Symptom Checker** – Get instant disease suggestions based on entered symptoms.
- 😰 **Stress Checker** – Analyze your stress levels and receive personalized suggestions.
- 🤖 **AI Chatbot** – Ask questions and get health-related advice.
- 📺 **YouTube Health Tips** – Fetches latest health-related videos using YouTube API.
- 📰 **Medibase** – Displays trending health news using NewsAPI.
- 📄 **Report Scanner** – Analyze and extract information from medical reports (OCR).
- 📚 Credit page listing all acknowledgments.

---

## 🛠️ Tech Stack

- **Backend**: Python, Flask
- **ML Models**: Trained with Scikit-learn / TensorFlow / Keras
- **Frontend**: HTML, CSS, Bootstrap (Jinja templates)
- **APIs**:
  - YouTube Data API
  - NewsAPI
- **Others**: Pandas, Joblib, OpenCV, Tesseract OCR


---

## 🔐 API Key Setup

Store your API keys in a `.env` file (do **not** commit this file):

```bash
YOUTUBE_API_KEY=your_youtube_api_key
NEWS_API_KEY=your_news_api_key
