import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

dataset=pd.read_csv("Position_Salaries.csv")
X=dataset.iloc[:,1:-1].values
Y=dataset.iloc[:,-1].values

from sklearn.ensemble import RandomForestRegressor


regressor=RandomForestRegressor(n_estimators=10,random_state=0)
regressor.fit(X,Y)

X_grid=np.arange(min(X),max(X),0.1)
X_grid=X_grid.reshape(len(X_grid),1)

plt.scatter(X,Y,color="red")
plt.plot(X_grid,regressor.predict(X_grid))
plt.title("Random Forest Regression")
plt.show()