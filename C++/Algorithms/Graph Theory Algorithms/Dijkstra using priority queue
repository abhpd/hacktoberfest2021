#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define mem(a, val) memset(a, val, sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define pb push_back
#define pp pop_back

using namespace std;

ll dist[1005];
ll MAXN = 1000000005;
void dijk(ll curr, ll n, ll m, vector<pair<ll, ll>> adj[])
{
   priority_queue<pair<ll, ll>> pq;
   mem(dist, MAXN);
   pq.push({0, curr});
   dist[curr] = 0;

   while (!pq.empty())
   {
      ll xdist, x;
      xdist = -pq.top().first;
      x = pq.top().second;
      pq.pop();
      for (auto &i : adj[x])
      {
         if (xdist + i.second < dist[i.first])
         {
            dist[i.first] = xdist + (i.second);
            pq.push({-dist[i.first], i.first});
         }
      }
   }
}
void solve()
{
   ll n, m, k;
   cin >> n >> m;
   vector<pair<ll, ll>> adj[n];
   for (ll i = 0; i < m; i++)
   {
      ll x, y, w;
      cin >> x >> y >> w;
      x -= 1;
      y -= 1;
      adj[x].push_back({y, w});
      adj[y].push_back({x, w});
   }
   ll d[n][n];
   for (ll i = 0; i < n; i++)
   {
      dijk(i, n, m, adj);
      for (ll j = 0; j < n; j++)
         d[i][j] = dist[j];
   }
   // for(int i=0;i<n;i++)
   // {
   //    for(int j=0;j<n;j++)cout<<d[i][j]<<" ";
   //    cout<<endl;
   // }
}

int main()
{
   std::ios::sync_with_stdio(false);
   int T = 1;
   // cin>>T;
   // cin.ignore(); must be there when using getline(cin, s)
   while (T--)
   {
      solve();
   }

   return 0;
}
