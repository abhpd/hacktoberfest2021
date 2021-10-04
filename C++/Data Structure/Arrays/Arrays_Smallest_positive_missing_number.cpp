#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "  Enter the number of elements in array " << endl;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    const int N = 1e6 + 2;
    bool check[N];
    for (int i = 0; i < N; i++)
    {
        check[i] = false; // False can also be represented by 0
    }                     // True can also be represented by 1

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            check[arr[i]] = true;
        }
    }
    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        if (check[i] == false)
        {
            ans=i;
            break;
        }
    }

    cout<<ans<<endl;

    return 0;
}
