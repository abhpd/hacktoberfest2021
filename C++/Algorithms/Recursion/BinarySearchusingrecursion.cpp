
//Binary Search using Recursion

#include <bits/stdc++.h>
using namespace std;
int bs(int arr[],int s,int l,int x)
{
    if(l>=s)
    {
        int mid=s+(l-s)/2;
        if(arr[mid]==x)
            return mid;
        if(arr[mid]>x)
            return bs(arr,s,mid-1,x)
        if(arr[mid]<x)
            return bs(arr,mid+1,l,x)
    }
    return -1;
}
int main()
{
   int t,n,x;
   cin>>t;
   while(t--)
   {
       cin>>n;
       int arr[n];
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
       }
       sort(arr,arr+n);
       int ans=bs(arr,0,n-1,x);
       cout<<ans<<" "<<arr[ans]<<endl; //Prints index and then the value required
   }
}