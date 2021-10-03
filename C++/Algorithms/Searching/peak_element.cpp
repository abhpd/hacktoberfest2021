// given an unsorted array , we have to find the peak element
// peak element- element which is not smaller than its neighbours/ greater than one and equal to other/
//               equal to both the neighbours

#include<bits/stdc++.h>
using namespace std;

int peak(int a[],int l,int h,int n)
{
    int m=(l+h)/2;

    // checking if middle element is peak
    if((m==n-1 || a[m]>=a[m+1] ) && (m==0 || a[m]>=a[m-1]))
    return a[m];

    // if left neighbour is greater then peak lies in the left half
    if(m>0 && (a[m-1]>a[m]))
    return peak(a,l,m-1,n);
    
    // if right neighbour is greater then the peak lies in right half
    return peak(a,m+1,h,n);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<peak(a,0,n-1,n);
    return 0;
}