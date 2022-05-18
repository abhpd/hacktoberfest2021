import numpy as np
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

X_train = np.load("train_data.npy")
X_test = np.load("test_data.npy")
y_train = np.load("train_labels.npy")
y_test = np.load("test_labels.npy")

print("X_train shape:",X_train.shape)
print("X_test shape: ",X_test.shape)

print("Normalizing data")
X_train = X_train/255.0
X_test = X_test/255.0

print("Reshaping data")
X_train = X_train.reshape(X_train.shape[0], 28*28)
X_test = X_test.reshape(X_test.shape[0], 28*28)

model = LogisticRegression(verbose = 1)
print("Training...")
model.fit(X_train, y_train)

print("Calculating training score")
predict = model.predict(X_train)
print("Training score:",accuracy_score(predict, y_train))

print("Calculating test score")
predict = model.predict(X_test)
print("Test score:",accuracy_score(predict, y_test))
