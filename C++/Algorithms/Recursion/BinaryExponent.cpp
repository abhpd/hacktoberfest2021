#include <bits/stdc++.h>
using namespace std;
long int bin_exp(long int base , long int power )
{
    if(power==0)
    {
        return 1;
    }
    else
    {
        long int temp =bin_exp(base,power/2);
        if(power%2 == 0)
            return (temp*temp);
        else
            return ((temp*temp)*base);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long int power,base;
    cin>>base>>power;
    cout<<bin_exp(base,power);

    return 0;
}
