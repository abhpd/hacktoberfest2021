#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<long> &a,long n) // n= size of vector
{
    long i,j;

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                swap(a[i],a[j]);
            }
        }
    }
}

int main()
{
    long n; // n= size of vector
    cin>>n;

    vector<long> a(n);
    for(long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    selectionSort(a,n);
    //output the array after sorting
    for(long i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}