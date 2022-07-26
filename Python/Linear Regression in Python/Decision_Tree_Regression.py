import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

dataset=pd.read_csv("Position_Salaries.csv")
X=dataset.iloc[:,1:-1].values
Y=dataset.iloc[:,-1].values

from sklearn.tree import DecisionTreeRegressor

decRegressor=DecisionTreeRegressor(random_state=0)
decRegressor.fit(X,Y)

X_grid=np.arange(min(X),max(X),0.1)
X_grid=X_grid.reshape(len(X_grid),1)


plt.scatter(X,Y,color="red")
plt.plot(X_grid,decRegressor.predict(X_grid))
plt.title("Decision Tree Regression")
plt.show()


