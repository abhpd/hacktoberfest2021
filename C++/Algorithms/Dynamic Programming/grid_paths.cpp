#include <bits/stdc++.h>
#define ll long long int
#define li long int
#define ld long double
using namespace std;

//Problem Link: https://cses.fi/problemset/task/1638/
//nanRex
 
ll modo = 1e9 + 7;
 
void solve(){
	ll n;
	cin >> n;
	char mat[n][n];
	ll dp[n][n];
	for(ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
			dp[i][j] = 0;
 
	for(ll i = 0; i < n;i++){
		for(ll j = 0; j < n; j++){
			cin >> mat[i][j];
		}
	}
 
	//edge cases
	if (mat[n-1][n-1] == '*'){
		cout << 0 << endl;
		return;
	}
	if (n==1){
		cout << 1 << endl; return;
	}
 
	for(ll i = n-2; i >= 0; i--)
		if (mat[i][n-1] == '.')
			dp[i][n-1]++;
		else
			break;
	for(ll j = n-2; j >= 0; j--)
		if (mat[n-1][j] == '.')
			dp[n-1][j]++;	
		else
			break;
 
	for(ll i = n-2; i >= 0; i--){
		for(ll j = n-2; j >= 0; j--){
			if(mat[i][j] == '.'){
				dp[i][j] = (dp[i+1][j] + dp[i][j+1])%modo;
			}
		}
	}
 
	cout << dp[0][0] << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
   // cin >> t;
    while (t--)
        solve();
 
    return 0;
}
