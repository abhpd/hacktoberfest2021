// https://cses.fi/problemset/task/1745
 
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
 
const int mod = 1e9 + 7;
int dp[int(101)][int(1e5+1)];

void subSetSum(int a[],int n,int sum){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]<=j)
                dp[i][j] = dp[i-1][j-a[i-1]]+dp[i-1][j];
            else    
                dp[i][j] = dp[i-1][j];
        }
    }
}

void solve_question()
{
    int n;
    cin>>n;
    int a[n];
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(int j=0;j<=sum;j++)
        dp[0][j]=0;
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    subSetSum(a,n,sum);
    vector<int> res;
    for(int j=1;j<=sum;j++)
        if(dp[n][j]!=0)
            res.push_back(j);
    cout<<res.size()<<"\n";
    for(int x:res)
        cout<<x<<" ";
    cout<<"\n";
    return;
}
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //freopen("looking.in","r",stdin);
    

    solve_question();
        
    return 0;
    
}