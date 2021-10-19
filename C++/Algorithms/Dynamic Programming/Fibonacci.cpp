#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    v[1] = 1;
    for (int i = 2; i <= n; i++)
        v[i] = v[i - 1] + v[i - 2];
    cout << "Nth fibonacci number is : " << v[n] << " ";
}