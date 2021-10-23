                            //Matrix Multiplication
#include<iostream>
using namespace std;
int main()
{
    int n,m,i,j,k,sum=0;
    cout<<"Enter the number of rows and columns in matrix 1: ";
    cin>>n>>m;
    int a,b;
     cout<<"Enter the number of rows and columns in matrix 2: ";
     cin>>a>>b;
     int m1[n][m],m2[a][b],m3[n][b];
     if(m!=a)
     {
         cout<<"We cannot multiply these two matrices"<<endl;
     }
     else{
         
         cout<<"Enter elements of matrix 1: "<<endl;
         for(i=0;i<n;i++)
         {
             for(j=0;j<m;j++)
             {
                 cin>>m1[i][j];
             }
         }
         cout<<"Enter the elements of matrix 2 : "<<endl;
         for(i=0;i<a;i++)
         {
             for(j=0;j<b;j++)
             {
                 cin>>m2[i][j];
             }
         }
         for(i = 0; i < n; ++i){
        for(j = 0; j < b; ++j)
        {
            m3[i][j]=0;
        }}
        for(i=0;i<n;i++)
        {
            for(j=0;j<b;j++)
            {
                sum=0;
                for(k=0;k<n;k++)
                {
                    m3[i][j]+=m1[i][k]*m2[k][j];
                }
                
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<b;j++)
            {
                cout<<m3[i][j]<<" ";
            }
            cout<<endl;
        }

     }
}