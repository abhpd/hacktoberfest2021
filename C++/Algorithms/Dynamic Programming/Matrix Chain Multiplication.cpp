//Matrix Chain Multiplication


/********
Given a sequence of matrices, find the most efficient way 
to multiply these matrices together. The efficient way is 
the one that involves the least number of multiplications.

The dimensions of the matrices are given in 
an array arr[] of size N (such that N = number of matrices + 1)
 where the ith matrix has the dimensions 
 (arr[i-1] x arr[i]).


*********/

/* Input:- N=5
 arr={40,20,30,10,30}
 Output:- 26000
*/
/****
 Explanation:There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.

****/


/**
Time Complexity:O(N^3)
Space Complexity:O(N^2) 
**/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
	//using the "memoization" algo to optimize the solution 
    int dp[501][501];
    int solve(int arr[],int i,int j){
        if(i>=j){
            return 0;
        }
        //if the solution is already present the matrix 
        //returning the ans from their itself
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mn=INT_MAX;
        //using the loop to check at every index if it is giving 
		//the minimum ans
        for(int k=i;k<j;k++){
        	//Creating a temporary ans
            int tempans= solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            //storing the min ans as it is required in the question
			if(tempans<mn){
                mn=tempans;
            }
        }
        //if the ans is not present int the matrix then storing
        //the ans
        return dp[i][j]=mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        //initializing the dp with -1
        memset(dp,-1,sizeof(dp));
        return solve(arr,1,N-1);
    }
};
// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    //for multiple testcases
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends
