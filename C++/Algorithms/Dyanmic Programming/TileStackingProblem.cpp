#include <bits/stdc++.h> 
using namespace std; 
#define N 1000 
  
int noOfPossibleWays(int n, int m, int k) 
{ 
    int dp[N][N]; 
    int presumarray[N][N]; 
    memset(dp, 0, sizeof dp); 
    memset(presumarray, 0, sizeof presumarray); 
  
    for (int i = 1; i < n + 1; i++) { 
        dp[0][i] = 0; 
        presumarray[0][i] = 1; 
    } 
  
    for (int i = 0; i < m + 1; i++) 
        presumarray[i][0] = dp[i][0] = 1; 

    for (int i = 1; i < m + 1; i++) { 

        for (int l = 1; l < n + 1; l++) { 

            dp[i][l] = presumarray[i - 1][l]; 
            if (l > k) { 
                dp[i][l] -= presumarray[i - 1][l - k - 1]; 
            } 
        } 

        for (int l = 1; l < n + 1; l++) 
            presumarray[i][l] = dp[i][l] + presumarray[i][l - 1]; 
    } 
  
    return dp[m][n]; 
} 
 
int main() 
{ 
	int n, m, k;
	cin >> n >> m >> k;
    cout << noOfPossibleWays(n, m, k) << endl; 
    return 0; 
} 