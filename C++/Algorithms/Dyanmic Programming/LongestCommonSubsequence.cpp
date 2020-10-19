int dp[1001][1001];

int LCSTopDown(string s, string t, int n, int m){
	for(int i=0; i<=m; i++)
		dp[0][i]=0;
	for(int i=0; i<=n; i++)
		dp[i][0]==0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s[i-1]==t[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j ]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n][m];
}
