#include <iostream>
using namespace std;

int tilingWays(int n)
{

    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return tilingWays(n - 1) + tilingWays(n - 2);
}

int main()
{

    cout << tilingWays(4) << endl;
    return 0;
}