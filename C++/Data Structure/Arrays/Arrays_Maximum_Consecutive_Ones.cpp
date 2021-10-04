#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<int> a(n);

    for (auto &i : a)
    {
        cin >> i;
    }

    int zerocnt = 0;
    int i = 0;
    int ans = 0;

    for (int j = 0; j < n; j++)
    {
        if (a[j] == 0)
        {
            zerocnt++;
        }
        while (zerocnt > k)
        {
            if (a[i] == 0)
            {
                zerocnt--;
            }
            i++;
        }
        ans = max(ans, (j - i + 1));
    }
    cout << ans;
}