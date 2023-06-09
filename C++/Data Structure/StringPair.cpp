# Data-structures
#include <iostream>
using name space std;
int main()
{
    int arr[100],arr3[100];
    int a,i,m=0,sum=0;
    cin>>a;
    for(i=0;i<a;i++)
    {
        cin>>arr[i];
    }
    char arr2[10];
    arr2[1]='one';
    arr2[2]='two';
    arr2[3]='three';
    arr2[4]='four';
    arr2[5]='five';
    arr2[6]='six';
    arr2[7]='seven';
    arr2[8]='eight';
    arr2[9]='nine';
    int arr4[10]={2,1,2,2,2,1,2,2,2};
    for(int k=0;k<3;k++)
    {
        for(int j=0;j<10;j++)
        {
            if(arr[k]==arr2[j])
            arr3[m]=arr4[j];
            m=m+1;
        }
    }
    for(int n=0;n<m;n++)
    {
        sum=sum+arr3[n];   
    }
    for(int l=0;l<a;l++)
    {
        int q,count=0;
        q=arr[l]+arr[l+1];
        if(sum==q)
        {
           count=count+1; 
        }
    }
    for(int r=0;r<10;r++)
    {
        if(count==arr2[r])
        {
            cout>>arr2[r];
        }
        
    }
}
