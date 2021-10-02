#include<iostream>
using namespace std;

//Objective : Simulate the josephus algorithm and find the last standing person 
//after eliminating the M th person continuously in a circle of N people

int josephus_recursive(int n,int m)
{
    if(n==1)
        return 1;
    int a=josephus_recursive(n-1,m);
    return (a+m-1)%n+1;
}

int josephus_iterative(int n,int m)
{
    int res=0;
    for(int i=1;i<=n;i++)
    {
        res=(res+m)%i;
    }
    return res+1;
}

int main()
{
    int n,m;
    //n - number of people in the circle
    //m - people from the current location to be eliminated
    cin>>n>>m;
    
    cout<<"JOSEPHUS ALGORITHM USING RECURSION : "<<josephus_recursive(n,m)<<'\n';
    cout<<"JOSEPHUS ALGORITHM USING ITERATION : "<<josephus_iterative(n,m)<<'\n';
    return 0;
}