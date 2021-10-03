// calculating n raised to power of p using Recursion

#include<bits/stc++.h>
using namespace std;

int power(int n, int p)
{
    if(p==0)
    {
        return 1;
    }
    int prevPower = power(n,p-1);
    return n*prevPower;

}

int main()
{
    int n,p;
    cout<<"Enter the number"<<endl;
    cin>>n;
    cout<<"Enter the power"<<endl;
    cin>>p;
    cout<<power(n,p)<<endl;

}
