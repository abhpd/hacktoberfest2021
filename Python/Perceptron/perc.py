import matplotlib.pyplot as plt
import numpy as np
import random as rd
import pandas as pd

def sgn(x,w):
    t = np.sum(x.T@w) / np.sum(w[1:]**2)
    return int(t / abs(t))


def distance(x,w):
    return np.sum(x.T@w)

feature_and_label = np.loadtxt('DATA.txt', delimiter=',')
#print | to check
#print(feature_and_label)

feature_and_label = np.hstack((np.ones((feature_and_label.shape[0],1)),feature_and_label))

t = []
for i in range(1,feature_and_label.shape[1]):
    t.append(rd.random())

w = np.array(t)
del t
t1 = [[0 if sgn(feature_and_label[i,:-1],w) == int(feature_and_label[i,-1]) else 1] for i in range(feature_and_label.shape[0])]
feature_and_label = np.concatenate((feature_and_label,np.array(t1)),axis = 1)
print(feature_and_label)
#check: ok
print(w)

ite = 0
coverged = np.count_nonzero(feature_and_label[:,-1] == 1)
print(coverged)
while coverged != 0 and ite < 300:
    print(w)
    print(feature_and_label, end ='\n\n\n\n\n')
    feature_and_label = np.random.permutation(feature_and_label)
    expected_label = feature_and_label[:,-2]
    missclassify = feature_and_label[:,-1]
    for i in range(feature_and_label.shape[0]):
        if int(missclassify[i]):
            w = w + np.sum(expected_label[i]) * feature_and_label[i,:-2]
    for i in range(feature_and_label.shape[0]):
        train_label = sgn(feature_and_label[i,:-2],w)
        if train_label == int(feature_and_label[i,-2]): feature_and_label[i,-1] = 0
        else: feature_and_label[i,-1] = 1
    coverged = np.count_nonzero(feature_and_label[:,-1] == 1)
    ite+=1
print(w)
print(ite)
col = {1:'blue', -1:'red'}
for i in range(feature_and_label.shape[0]):
    plt.scatter(feature_and_label[i,1],feature_and_label[i,2], color=col[feature_and_label[i,3]])

x_coor = [i/100 for i in range(101)]
y_coor = [(-w[0] - w[1]*i)/w[2] for i in x_coor]
plt.plot(x_coor,y_coor)
plt.show()

