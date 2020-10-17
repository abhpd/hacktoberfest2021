#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb  push_back
#define scan(a,n)  for(int i = 0; i < n;i++)cin >> a[i];
#define print(a,n)  for(int i = 0;i < n;i++)cout <<a[i] <<' ';cout<<endl;
#define endl  '\n'
#define vi  vector<int>
#define rng(x) x.begin(),x.end()

// Tushar Goyal : Chalie Shuru karte hai

void solve()
{
	int n; cin >> n;
	vi x(n);
	scan(x, n);
	print(x, n);

	vi lis;

	for (int i = 0 ; i < n ; i++)
	{
		if (lis.empty() or x[i] > lis.back())lis.pb(x[i]);
		else
		{
			int idx = lower_bound(rng(lis), x[i]) - lis.begin();
			lis[idx] = x[i];
		}
	}

	cout << lis.size() << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
