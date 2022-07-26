import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

dataset=pd.read_csv("Position_Salaries.csv")
X=dataset.iloc[:,1:-1].values
Y=dataset.iloc[:,-1].values

from sklearn.preprocessing import StandardScaler
ss_X=StandardScaler()
ss_Y=StandardScaler()
Y=Y.reshape(len(Y),1)

X=ss_X.fit_transform(X)
Y=ss_Y.fit_transform(Y)


from sklearn.svm import SVR
svr=SVR(kernel="rbf")
svr.fit(X,Y)

plt.scatter(ss_X.inverse_transform(X),ss_Y.inverse_transform(Y),color="red")
plt.plot(ss_X.inverse_transform(X),ss_Y.inverse_transform(svr.predict(X)))
plt.title("Support Vector Regression")
plt.show()

n=float(input("how many years of experiance do you have ? : "))
y_pred=svr.predict(ss_X.transform([[n]]))
y_proper=ss_Y.inverse_transform(y_pred)
print(Y_proper)
