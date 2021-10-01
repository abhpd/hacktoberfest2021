#include <iostream>
using namespace std;
int knap(int *value,int *weight,int n,int k){
    int dp[n+1][k+1];
    int i,j;
    for(j=0;j<k+1;j++)
    dp[0][j]=0;
    for(i=0;i<n+1;i++)
    dp[i][0]=0;
    for(i=1;i<n+1;i++){
        for(j=1;j<k+1;j++){
            if(j>=weight[i-1]){
                if(dp[i-1][j]>dp[i-1][j-weight[i-1]]+value[i-1])
                dp[i][j]=dp[i-1][j];
                else
                dp[i][j]=dp[i-1][j-weight[i-1]]+value[i-1];
            }
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][k];
    
}
int main() {
int value[]={15,14,10,45,30};
int weight[]={2,5,1,3,4};
int n=sizeof(value)/sizeof(value[0]);
int k=7;
cout<<knap(value,weight,n,k);
	return 0;
}
