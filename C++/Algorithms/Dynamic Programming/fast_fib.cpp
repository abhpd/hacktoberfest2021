#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

//driver code
int main(){
    ll n ;
    cout << "Enter no of terms : " ;
    cin >> n ;
   
    //using DP (storing previously calculated terms in array) to achieve a fast fibonacci series
    
    ll dp[n+1];

    //F0 = 0
    //F1 = 1
    //Fn = Fn-1 + Fn-2
    
    dp[0] = 0;
    dp[1] = 1;

    if(n == 0){
        cout << "Please enter a natural number (n >= 1)" << endl ;
    }
    else if(n == 1){
        cout << dp[0] ;
    }
    else if(n == 2){
        cout << dp[0] << " " << dp[1];
    }
    else{
        //printing first two terms
        cout << dp[0] << " " << dp[1];
        
        //printing terms upto Fn
        for(ll i = 2 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2] ;
            cout << " " << dp[i] ;
        }
    }
    return 0 ;
}
