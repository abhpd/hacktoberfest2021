#include <bits/stdc++.h>
#define ll long long int
#define omar main
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//priority_queue push_back make_pair emplace vector double float unordered_map unordered_set queue stack sort begin resize clear second first continue break
using namespace std;
const int N = 131072;
vector<ll>arr(N, 0);
vector<ll>seg(N*2, 0);
unordered_map<ll, pair<ll, ll>>intv;
ll n, m; 
ll build(ll idx, ll l, ll r){
	ll &node = seg[idx];
	ll mid = l + ((r - l) / 2);
	intv[idx] = {l, max(l, r)};
	if (mid < 0 || l > r)return 0;
	if (l == r) return node = arr[l];
	return node = build(2 * idx, l, mid) + build((2 * idx) + 1, mid + 1, r);
}
void update(ll idx, ll i, ll val){
	ll &node = seg[idx];
	ll l = intv[idx].first, r = intv[idx].second;
	if ((i < l)|| (i > r)) return;
	if ((i == l) && (i == r)) node = val;
	else{
		update(idx * 2, i, val);
		update((idx * 2) + 1, i, val);
		node = seg[idx * 2] + seg[(idx * 2) + 1];
	}
	
}
ll sum(ll idx, ll l, ll r){
	ll x = intv[idx].first, y = intv[idx].second;
	if ((x >= l) && (y <= r)) return seg[idx];
	if ((l < x && r < x) || (l > y && r > y))return 0;
	return sum(idx * 2, l, r) + sum((idx * 2) + 1, l, r);
}
int omar(){ //fastIO
}
