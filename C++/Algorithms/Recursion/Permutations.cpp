#include<bits/stdc++.h>
using namespace std;

static int sol[100];  
static int n=0;
void permute(int a[],int idx)
{
    if(idx==n)
    {
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=idx;i<n;i++)
    {
        if(i!=idx && a[i]==a[idx])
        continue;
        int p=a[i];
        a[i]=a[idx];
        a[idx]=p;
        permute(a,idx+1);
        p=a[i];
        a[i]=a[idx];
        a[idx]=p;
    }
}

int main()
{
    
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    permute(a,0);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}