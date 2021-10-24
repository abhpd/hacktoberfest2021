//program to find the minimum number of painters required to paint given number of boards
// complexity: O(log n)
#include<bits/stdc++.h>
using namespace std;
bool isVALID(int *arr,int n,int k,int mid) // function to check validity i.e. checking if no. of painters are equal or not
{
    int painter=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        if(sum>mid)
        {
            painter++;
            sum=arr[i];
        }
        if(painter>k)
        return false;
    }
    return true;
}
int maxinarray(int *arr,int n) //returns max element of array
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>=max)
        max=arr[i];
    }
    return max;
}
int sumofallarrayelements(int *arr,int n) //returns sum of all elements of array
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    return sum;
}
int main()
{
    int n,k,ans;
    cout<<"ENTER NUMBER OF BOARDS: ";
    cin>>n;
    cout<<"ENTER NUMBER OF PAINTERS: ";
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"ENTER LENGTH OF BOARD "<<i+1<<" : ";
        cin>>arr[i];
    }
    if(k>n)
    printf("PAINTING NOT POSSIBLE");
    else
    {
        int start=maxinarray(arr,n),end=sumofallarrayelements(arr,n);
        while(start<=end) //binary searching for finding the minimum possible number of painters
        {
            int mid=start+((end-start)/2);
            if(isVALID(arr,n,k,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        cout<<"THE MINIMUM TIME REQUIRED WILL BE: "<<ans<<"units";
    } 
}
