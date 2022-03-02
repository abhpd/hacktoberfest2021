#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int k = 1; k <= i - 1; k++)
            cout << " ";
        cout << "*";
        for (int j = 1; j <= 2 * n - 2 * i - 1; j++)
            cout << " ";
        cout << "*";
        cout << endl;
    }
    for (int i = 1; i < n; i++)
        cout << " ";
    cout << "*";
    cout << endl;
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
            cout << " ";
        cout << "*";
        for (int j = 1; j < 2 * (n - i) - 1; j++)
            cout << " ";
        cout << "*";
        cout << endl;
    }
}
