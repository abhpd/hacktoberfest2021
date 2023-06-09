#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int t[9][9];



int rodcut(int w[], int v[], int wt ,int n)
{

if(n<0)
return 0;

if(t[wt][n]!=-1)
return t[wt][n];

if(w[n-1]<=wt)
{      
    return t[wt][n] = max (v[n-1] + rodcut( w,v, wt-w[n-1] ,n),rodcut(w, v, wt, n-1));
}
else
return t[wt][n] = (rodcut(w, v, wt, n-1));

}

int main()
{

memset (t,-1, sizeof(t));
int wt = 8;
int w[] = {1,2,3,4,5,6,7,8};
int v[] = {1,5,8,9,10,17,17,21};

cout<< rodcut(w,v,wt,8);

return 0;

}
