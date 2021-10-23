#include<bits/stdc++.h>
#define MAX 1e5+1 // assuming maximum value of an element in an array is 100000.
using namespace std;

void countSort(vector<long> &a,long n) // n= size of vector
{
    long i,j;

    vector<long> store(MAX);
    for(i=0;i<n;i++)
    {
        store[a[i]]++;
    }

    long k=0;
    for(i=0;i<=MAX;i++)
    {
        for(j=0;j<store[i];j++)
        {
            a[k]=i;
            k++;
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
    countSort(a,n);
    //output the array after sorting
    for(long i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}