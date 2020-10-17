import matplotlib.pyplot as plt
import numpy as np

plt.style.use("fivethirtyeight")
# import necessary library, framework


x = np.loadtxt('DATA.txt', delimiter = ',')

#x = np.asarray(x)
col = {-1: 'red', 1: 'blue'}
for i in range(x.shape[0]):
    label = x[i, -1]
    feature_x, feature_y = x[i,0], x[i,1]
    plt.scatter(feature_x, feature_y, color = col[label])

plt.xlabel('dien tich')
plt.ylabel('gia')
plt.show()
