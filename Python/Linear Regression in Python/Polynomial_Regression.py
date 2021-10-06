import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

dataset=pd.read_csv("Position_Salaries.csv")
X=dataset.iloc[:,1:-1].values
Y=dataset.iloc[:,-1].values

from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures

pf=PolynomialFeatures(degree=6)

X_extra=pf.fit_transform(X)

poly_regression=LinearRegression()

poly_regression.fit(X_extra,Y)

y_pred=poly_regression.predict(pf.fit_transform([[6.5]]))
print(y_pred)

plt.scatter(X,Y,color="red")
plt.plot(X,poly_regression.predict(X_extra))
plt.title("Polynomial_regression")
plt.show()