//Given numbers array in which every numbers appears twice except one number find that number
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int res=0;
    for(int i=0;i<n;i++)
        res^=arr[i];
    cout<<res;
    return 0;
}
