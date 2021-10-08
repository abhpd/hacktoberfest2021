#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cout<<"N= ";
cin>>n;

int a[n+1];

cout<<"Enter unsorted array= ";
for (int i = 0; i < n; i++)
{
    cin>>a[i];
}

int s;
cout<<"SUM to be found in the SUBARRAY= ";
cin>>s;
int sum=0;

for (int i = 0; i < n; i++)
{
    sum=0;
    for (int j = i; j < n; j++)
    {
        sum=sum+a[j];
        if(sum==s){

            cout<<i+1<<" "<<j+1;exit(0);
        }
    }
    
}

cout<<"SUM NOT found in the SUBARRAY!!! ";

return 0;
}