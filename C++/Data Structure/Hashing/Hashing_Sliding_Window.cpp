#include <iostream>
using namespace std;
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

// #define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

signed main()
{

    int n, k;
    cin >> n >> k;

    vi a(n);

    rep(i, 0, n)
            cin >> a[i];

    int sum = 0, ans = INT_MAX;

    rep(i, 0, k)
    {
        sum += a[i];
    }

    ans = min(ans, sum);

    //Sliding Window
    rep(i, 1, n - k + 1)
    {
        sum -= a[i - 1];
        sum += a[i + k - 1];
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}