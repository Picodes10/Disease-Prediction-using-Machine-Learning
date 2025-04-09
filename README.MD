# Human Disease Prediction System using Machine Learning

## Overview

This repository contains a comprehensive **Disease Prediction System** that leverages machine learning models to predict the likelihood of various diseases based on user inputs. The system covers:

- **Heart Disease**
- **Liver Disease**
- **Stroke Risk**
- **Diabetes**
- **Parkinson's Disease**
- **Alzheimer's Risk Prediction** (newly added with optimized feature set)

The application uses a web interface built with **Flask** and **Jinja2 templates**, allowing users to select a disease and make predictions using pre-trained machine learning models.

## Key Features

- **Multi-Disease Prediction Platform**: Single interface for 6 different disease predictions
- **Advanced ML Models**: Uses diverse algorithms including Neural Networks and XGBoost
- **Optimized Alzheimer's Prediction**: Newly added with clinically validated 14-feature model
- **Web Interface**: Intuitive Flask-based interface with responsive design
- **Real-Time Predictions**: Instant risk assessment based on input parameters

### Disease Modules:
- Diabetes Prediction
- Heart Disease Prediction
- Liver Disease Prediction
- Parkinson's Disease Prediction
- Stroke Risk Prediction
- Alzheimer's Risk Prediction (new)

## Machine Learning Algorithms

The system employs multiple state-of-the-art algorithms:

- **Logistic Regression**: For binary classification tasks
- **Random Forest**: Ensemble method combining multiple decision trees
- **Support Vector Machines (SVM)**: For high-dimensional data
- **K-Nearest Neighbors (KNN)**: Distance-based classification
- **Decision Trees**: Rule-based classification
- **Naive Bayes**: Probabilistic classifier
- **XGBoost**: Gradient boosting for improved accuracy
- **Neural Networks**: Deep learning models for complex patterns

### Alzheimer's Model Optimization
The newly added Alzheimer's prediction uses only these clinically significant features:
1. Age
2. Family History
3. Depression
4. Head Injury
5. Hypertension
6. MMSE Score
7. Memory Complaints
8. Behavioral Problems
9. ADL (Activities of Daily Living)
10. Confusion
11. Disorientation
12. Personality Changes
13. Difficulty Completing Tasks
14. Forgetfulness

## Technology Stack

- **Backend**:
  - Python (Pandas, NumPy, Scikit-learn)
  - Flask web framework
  - Joblib/Pickle for model serialization

- **Frontend**:
  - HTML5, CSS3, JavaScript
  - Bootstrap for responsive design
  - Jinja2 templating

- **Machine Learning**:
  - Scikit-learn
  - XGBoost
  - TensorFlow/Keras for Neural Networks

## Getting Started

```bash
git clone https://github.com/yourusername/Disease-Prediction.git
cd Disease-Prediction
pip install -r requirements.txt
flask run
```