# Disease Prediction System using Machine Learning

## Overview

This repository contains a **Disease Prediction System** that leverages machine learning models to predict the likelihood of various diseases based on user inputs. The system covers the following diseases:

- **Heart Disease**
- **Liver Disease**
- **Stroke Risk**
- **Diabetes**
- **Parkinson's Disease**

The application uses a web interface built with **Flask** and **Jinja2 templates**, allowing users to select a disease and make predictions using pre-trained machine learning models.

## Features

- **User-Friendly Interface**: The system provides an intuitive and easy-to-use web interface where users can select a disease for prediction.
- **Machine Learning Models**: Pre-trained models are used for predicting disease risk. These models are built using popular machine learning algorithms.
- **Multiple Disease Predictions**: The system supports predictions for various diseases:
    - **Diabetes Prediction**
    - **Heart Disease Prediction**
    - **Liver Disease Prediction**
    - **Parkinson’s Disease Prediction**
    - **Stroke Risk Prediction**
- **Real-Time Predictions**: Once the user selects a disease, they can input their data, and the system predicts the likelihood of the disease in real-time.

## Algorithms Used

Each disease prediction model is trained using one or more of the following machine learning algorithms:

- **Logistic Regression**: Used for binary classification tasks such as predicting the presence or absence of a disease.
- **Random Forest Classifier**: An ensemble learning algorithm that combines multiple decision trees to improve prediction accuracy.
- **Support Vector Machine (SVM)**: A powerful classifier used for high-dimensional data, useful for disease prediction when the data is complex.
- **K-Nearest Neighbors (KNN)**: A simple, yet effective algorithm for classification based on the distance to the nearest neighbors.
- **Decision Tree Classifier**: A decision tree-based model used for classification tasks, which splits data based on feature values.
- **Naive Bayes**: A probabilistic classifier used for diseases where the features are conditionally independent.

The choice of algorithm depends on the nature of the disease data and the features used for prediction. The models are trained on relevant datasets and then saved as `.pkl` files for real-time prediction.

## Technologies Used

- **Flask**: A lightweight Python web framework used for building the web application.
- **Python**: The core programming language for model development and server-side logic.
- **Machine Learning Models**: Trained using popular machine learning algorithms as mentioned above.
- **HTML/CSS**: Used for creating and styling the web interface.
- **Jinja2 Templates**: Templating engine used by Flask to dynamically render content.