#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//vector<vector<int>> t;
int t[21][21];

int knapsack(int w[] , int v[] , int wt , int n)
{
int i,j;

for(i=1;i<=n;i++) 
for(j=1;j<=wt;j++)
{   
    if(w[i-1]<=j)
    t[i][j] = max(v[i-1] + t[i-1][j-w[i-1]] , t[i-1][j]);
    else
    t[i][j] = t[i-1][j];

}

return t[n][wt];

}


int main()
{

memset(t,-1,sizeof(t));

int w[] = {1,3,4,7};
int v[] = {5,4,5,6};
int wt = 7;

for(int i=0;i<=4;i++)
for(int j=0; j<=wt;j++)
    {
        if(i==0 || j==0)
        t[i][j]=0;
    }

cout<< knapsack(w, v ,wt,4);
return 0;

}