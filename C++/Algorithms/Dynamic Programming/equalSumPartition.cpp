
#include <bits/stdc++.h>
using namespace std;

int equalPartition(int N, int arr[])
    {
        int sum = 0 ; 
        for(int i = 0 ; i < N ; i++){
            sum+=arr[i]; 
        }
        
        if(sum%2 != 0) return 0;
        
        int dp[N+1][(sum/2)+1];
        
        for(int i = 0 ; i <= N; i++){
            for(int j = 0 ; j <= (sum/2); j++){
                if(i==0){
                    dp[i][j]= 0; 
                }
                if(j==0){
                    dp[i][j]=1; 
                }
                
                if(i>0 and j >0){
                    if(arr[i-1]<=j){
                        dp[i][j] = max(dp[i-1][j-arr[i-1]], dp[i-1][j]);
                    }else{
                        dp[i][j]= dp[i-1][j];
                    }
                }
            }
        }
        
        return dp[N][sum/2];
    }

int main()
{
    int arr[] = { 3, 1, 1, 2, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
     
    // Function call
    if (findPartiion(arr, n) == true)
        cout << "Can be divided into two subsets of equal "
                "sum";
    else
        cout << "Can not be divided into"
             << " two subsets of equal sum";
    return 0;
}