import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.tree import DecisionTreeClassifier
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, accuracy_score

dataset=pd.read_csv("D:\Downloads\TicTacToeEndgame.csv") 
dataset.mean=dataset

dataset.head()


# # Data set description

# total number of observations
n= dataset.shape[0]
# number of features
n_features=dataset.shape[1]-1

dataset.replace(to_replace=['x'], value=1, inplace=True)
dataset.replace(to_replace=['o'], value=2, inplace=True)
dataset.replace(to_replace=['b'], value=3, inplace=True)
dataset["V10"].replace(to_replace=['positive'], value=1, inplace=True)
dataset["V10"].replace(to_replace=['negative'], value=0, inplace=True)
# number of succesfull outcomes
success=dataset[dataset['V10']==1].shape[0]
# number of losses
loss=dataset[dataset['V10']==0].shape[0]
print("total number of patients: {} ".format(n))
print("number of features: {}".format(n_features))
print("number of wins: {}".format(success))
print("number of loss: {}".format(loss))
dataset.head()

# extracting feature columns
features_cols=list(dataset[0:9])

#show the list of columns
print("features columns:\n{}".format(features_cols))

#separate the data into features data and target data
x=dataset[features_cols]
y=dataset['V10'].values

print("feature values:")
x.head

#split the data set into training and testing data
x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.30,random_state=5)
print(x_train)


#dimension of training and testing data
print(x_train.shape)
print(x_test.shape)


# Normalization Step

from sklearn.preprocessing import StandardScaler 
scaler=StandardScaler()

scaler.fit(x_train)

x_train = scaler.transform(x_train)

print("----After Z-score Normalization on X_train--- --")

print (x_train)

scaler.fit(x_test)
x_test= scaler.transform(x_test)
print("----After Z-score Normalization on X_test-------")
print (x_test)

# Fit the Model using ID3 Classifier

#training and prediction through a Descision Tree Classifier

for i in range(1,6):
    dtree_model= DecisionTreeClassifier(criterion='entropy', max_depth =i)
    dtree_model.fit(x_train, y_train) # Training
    dtree_predictions = dtree_model.predict (x_test) # Testing
    # accuracy on x_test
    accuracy = accuracy_score (dtree_predictions, y_test) 
    print("Accuracy for depth="+str(i)+":", accuracy)
    # creating a confusion matrix
    cm = confusion_matrix(y_test, dtree_predictions) 
    print (cm)

# Test the Model using CART Classifier
#training and prediction through a Descision Tree Classifier
for i in range (1,6):
    dtree_model= DecisionTreeClassifier (criterion='gini',max_depth =1) 
    dtree_model.fit (x_train, y_train)
    dtree_predictions = dtree_model.predict(x_test)
    #print(dtree_predictions)
    # accuracy on X_test
    accuracy = accuracy_score(y_test, dtree_predictions) 
    print("Accuracy for depth="+str(i)+":", accuracy) 
    # creating a confusion matrix
    cm = confusion_matrix(y_test, dtree_predictions) 
    print (cm)
