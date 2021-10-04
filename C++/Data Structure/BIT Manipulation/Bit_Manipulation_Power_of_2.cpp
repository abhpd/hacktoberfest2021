#include <iostream>
using namespace std;

bool ispowerof2(int n)
{

    if (n < 1)
        return false;

    if (n & n - 1)
        return false;

    return true;
}

int main()
{

    cout << ispowerof2(16) << endl;
    return 0;
}