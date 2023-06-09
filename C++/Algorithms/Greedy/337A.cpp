#include<bits/stdc++.h>
using namespace std;
     
int main(){
     int n,m,min,x,i;
     vector<int> f;
     cin>>n>>m;
     for(i=0;i<m;i++)
     {
          cin>>x;
          f.push_back(x);
     }
     sort(f.begin(),f.end());
     min=f[n-1]-f[0];
     for(i=1;i<m-n+1;i++)
     {
          if(min>f[n+i-1]-f[i])
          {
               min=f[n+i-1]-f[i];
          }
     }
     cout<<min;
     return 0;
}