# Import the required libraries

import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
from sklearn import datasets

class LogisticRegression:

  def __init__(self, lr, n_iters):
    self.lr = lr
    self.n_iters = n_iters
    self.weights = None
    self.bias = None


  def sigmoid(self, z):
    return 1/(1+np.exp(-z))

  def fit(self, X, y):
    n_samples, n_features = X.shape
    self.weights = np.zeros(n_features)
    self.bias = 0

    for _ in range(self.n_iters):
      linear_model = np.dot(X, self.weights) * self.bias
      y_predicted = self.sigmoid(linear_model)

      dw = 1/(n_samples) * np.dot(X.T, y_predicted - y)
      db = 1/(n_samples) * np.sum(y_predicted - y)

      self.weights -= self.lr * dw
      self.bias -= self.lr * db
  

  def predict(self, X):
    linear_model = np.dot(X, self.weights) * self.bias
    y_predicted = self.sigmoid(linear_model)
    y_predicted_cls = [1 if i > 0.5 else 0 for i in y_predicted]
    return y_predicted_cls

bc = datasets.load_breast_cancer()
X, y = bc.data, bc.target

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 1234)

def accuracy(y_true, y_predicted):
  accuracy = np.sum(y_true == y_predicted) / len(y_true)
  return accuracy

regressor = LogisticRegression(lr = 0.0003, n_iters=100000)
regressor.fit(X_train, y_train)

predictions = regressor.predict(X_test)

print("Accuracy:", accuracy(y_test, predictions))
