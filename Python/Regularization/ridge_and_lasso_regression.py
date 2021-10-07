import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import cross_val_score
from sklearn.linear_model import LinearRegression
from sklearn.linear_model import Ridge
from sklearn.linear_model import Lasso
from sklearn.model_selection import GridSearchCV
from sklearn.model_selection import train_test_split


from sklearn.datasets import load_boston

df = load_boston()

dataset = pd.DataFrame(df.data)

dataset.columns = df.feature_names

dataset['Price'] = df.target

X = dataset.iloc[:,:-1]
y = dataset.iloc[:,-1]

lin_reg = LinearRegression()
mse = cross_val_score(lin_reg, X, y, scoring='neg_mean_squared_error',cv=5)
mean_mse = np.mean(mse)
print(mean_mse)

ridge = Ridge()
parameters = {'alpha':[1e-15,1e-10,1e-8,1e-3,1e-2,1,5,10,20,30,35,40,45,50,55,100]}
ridge_reg = GridSearchCV(ridge,parameters,scoring='neg_mean_squared_error',cv=5)
ridge_reg.fit(X,y)

print(ridge_reg.best_params_)
print(ridge_reg.best_score_)

lasso = Lasso()
parameters = {'alpha':[1e-15,1e-10,1e-8,1e-3,1e-2,1,5,10,20,30,35,40,45,50,55,100]}
lasso_reg = GridSearchCV(lasso, parameters, scoring='neg_mean_squared_error',cv=5)

lasso_reg.fit(X,y)
print(lasso_reg.best_params_)
print(lasso_reg.best_score_)

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=0)

prediction_lasso = lasso_reg.predict(X_test)
prediction_ridge = ridge_reg.predict(X_test)

sns.distplot(y_test - prediction_lasso)

sns.distplot(y_test - prediction_ridge)



