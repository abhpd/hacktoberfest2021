// Created by Akshar Singh

#include<bits/stdc++.h>
using namespace std;

// Given a total sum and a set of non negative numbers, whether there exist a subset of numbers whose sum totals the given sum?

// Bottom up dp approach
char budp(int sum,int subset[],int l){
    char dp[100][100];
for(int i=0;i<=l;i++){
    for(int j=0;j<=sum;j++){
        if(i==0){
            dp[i][j] = 'F';
        }
        else if(j==0){
            dp[i][j] = 'T';
        }
        else{
            if(subset[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            else if(subset[i-1]==j){
                dp[i][j] = 'T';
            }
            else {
                if(dp[i-1][j]=='T'){
                    dp[i][j] = 'T';
                }
                else{
                    dp[i][j] = dp[i-1][j-subset[i-1]];
                }
            }
        }

    }
}

return dp[l][sum];
}
int main(){
    cout<<"Enter the total sum:-";
    int sum; cin>>sum;
    cout<<"Enter the size of the set :-";
    int n ; cin>>n;
    cout<<"Enter the values for the set :-";
    int subset [n] ;
    for(int i=0;i<n;i++){
        int x ; cin>>x;
        subset[i] = x;
    }
    cout<<budp(sum,subset,n);

    
}

// Eg test case :-
// sum = 11
// size = 5
// values = 2 3 7 8 10
// output - T(True)
