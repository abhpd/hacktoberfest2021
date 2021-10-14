#!/usr/bin/env python
# coding: utf-8

# ## Matrix Chain Multiplication

# In[9]:


def solve(arr,i,j,t):
    ans=float('inf')
    if (i>=j):
        return 0;
    elif(t[i][j]!=-1):
        return t[i][j]
    for k in range(i,j):
        tempans=solve(arr,i,k,t)+solve(arr,k+1,j,t)+arr[i-1]*arr[k]*arr[j]
        ans=min(ans,tempans)
    t[i][j]=ans    
    return t[i][j]


# In[10]:


arr=[10, 20, 30, 40, 30]
t=[[-1 for i in range(len(arr)+1)] for j in range(len(arr)+1)]
solve(arr,1,len(arr)-1,t)





