#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    int a[n+1];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=2;i<n;i++)
    {
        if(a[i]-a[i-1]!=a[i-1]-a[i-2])
        {
            for(j=n;j>i;j--)
            {
                a[j]=a[j-1];
            }
            a[i]=a[i-1]+(a[i-1]-a[i-2]);
            break;
        }
    }
    for(i=0;i<=n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}