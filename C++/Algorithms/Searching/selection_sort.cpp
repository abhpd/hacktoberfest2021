#include<iostream>
using namespace std;

void selection_sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min =a[i];
        int minIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                minIndex = j;
            }
        } 

        swap(a[minIndex],a[i]);  
    }
}


int main()
{
    int a[6] = {1,4,5,3,12,-3};
    int  n=6;

    selection_sort(a,n);
    cout<<"Sorted Array is : "<<endl;

    for(int i=0;i<6;i++)
    {

        cout<<a[i]<<" ";
    }


    return 0;
}