#include <iostream>
#include <climits>
#include <bits/stdc++.h> 
#include <cstring>
#include <vector>
using namespace std;
int dp[100][100];
int longestcommon(string a,string b,int i,int j){
    //base case
    if(a[i]=='\0' || b[j]=='\0'){
        return 0;
    }
    //rec case
    if(a[i]==b[j]){
        
        return 1+longestcommon(a,b,i+1,j+1);
    }else{
        int op1,op2;
        op1=op2=-1;
        op1=longestcommon(a,b,i+1,j);
        op2=longestcommon(a,b,i,j+1);
        return max(op1,op2);
    }
}

//dp-bottom up-2D

int longestSubseq(string a,string b){
    int row=a.length();
    int col=b.length();
    // int dp[row+1][col+1];
    for(int i=0;i<=row;i++) dp[i][0]=0;
    for(int j=0;j<=col;j++) dp[0][j]=0;

    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[row][col];
}

//printing lcs
string printlcs(int row,int col,string a,string b){
    string s="";
    int i=row;
    int j=col;
        while(i>=1 || j>=1){
            if(a[i-1]==b[j-1]){
                s+=a[i-1];
                i--;
                j--;
            }else{
                if(dp[i][j-1]>dp[i-1][j]){
                    j--;
                }else{
                    i--;
                }
            }
        }
        reverse(s.begin(),s.end());
        return s;
}

int main(){
    string a,b;
    cin>>a>>b;
    int row=a.length();
    int col=b.length();
    int k=longestcommon(a,b,0,0);
    //print lcs
    int i=row;
    int j=col;
    string res;
    while(i>0 && j>0){
        if(a[i]==b[j]){
            res+a[i];
            i--;
            j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    

    cout<<endl;
}