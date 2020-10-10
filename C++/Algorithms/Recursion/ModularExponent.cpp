#include <bits/stdc++.h>
using namespace std;
long int bin_exp(long int base , long int power, int m )
{
    base = base % m;
    if (power == 0)
    {
        return 1;
    }
    else
    {
        long int temp = bin_exp(base, power / 2);
        if (power % 2 == 0)
            return ((temp % m) * (temp % m)) % m;
        else
            return ((temp % m) * (temp % m) * base) % m;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long int power, base;
    cin >> base >> power;
    cout << bin_exp(base, power);

    return 0;
}
