#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<long> &a,long n) // n= size of vector
{
    long i,j;

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]>a[i])
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
    insertionSort(a,n);
    //output the array after sorting
    for(long i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}