#include<bits/stdc++.h>
using namespace std;
int kadane(vector<int> &v)
{
    int n=v.size(),temp=v[0],ans=v[0];
    for(int i=1;i<n;i++)
    {
        temp=max(v[i],temp+v[i]);
        ans=max(temp,ans);
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<"Maximum sum contiguous subarray = "<<kadane(v);
    return 0;
}