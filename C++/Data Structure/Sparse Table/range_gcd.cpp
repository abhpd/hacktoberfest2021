// template to implement sparse table for finding gcd in a range 
// the user input is stored in "vector<int> dataVector"
// a global sparse table is built on dataVector

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

vector<vector<ll>> sparse_table(1001, vector<ll>(21));

void build(vector<vector<ll>>& sparse_table, ll n, vector<ll> dataVector){
    for (ll i = 1;i<=n;i++) sparse_table[i][0] = dataVector[i];

    for (int j = 1;j<=20;j++){
        for (int i = 1;i + (1<<j) <= n + 1;i++){
            sparse_table[i][j] = __gcd(sparse_table[i][j - 1],
                sparse_table[i + (1<<(j - 1))][j - 1]);
        }
    }
}

ll query(vector<vector<ll>>& sparse_table, ll l, ll r, vector<ll> dataVector){
    ll val = dataVector[l];
    for (int j = 20;j>=0;j--){
        if ((1<<j) <= r - l + 1){
            val = __gcd(val,sparse_table[l][j]);
            l += (1<<j);
        }
    }
    return val;
}

int main(){
    // don't forget to resize sparse_table for each test case
    int n;
    sparse_table.clear(); sparse_table.resize(n, vector<ll>(21));
}