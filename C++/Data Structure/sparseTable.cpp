Sparse Table - It can be used on Idempotent functions like GCD, min, max

#include<bits/stdc++.h>
using namespace std;

// Driver Function
int main(){

    int n;
    cin>>n;
    int a[n+1];

    REP(i,n){
        cin>>a[i];
    }

    int logs[n+1];
    logs[1] = 0;
    for (int i = 2; i <= n; i++) {
        logs[i] = logs[i / 2] + 1;
    }

    // build sparese table dp[i][j]
    // 2^i length and j is the starting point
    int dp[21][10005];
    for(int i = 0; i < n; i++){
        int curlen = (1<<i);
        for(int j = 0; j <= n-curlen; j++){
            if(curlen == 1){
                dp[i][j] = a[j];
            }
            else{
                dp[i][j] = min(dp[i-1][j], dp[i-1][j+curlen/2]);
            }
        }
    }
    
    // Query
    
    int l,r;
    cin>>l>>r;
    int p = logs[r-l+1];
    int plen = (1<<p);
    cout<<min(dp[p][l], dp[p][r-plen+1]);

}
