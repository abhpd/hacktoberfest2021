/*

Algorithm: 
DP state: The state subset[i][j] will be true if there exists a subset of elements from A[0….i] with sum value = ‘j’. 
DP transition: 
			if (arr[i-1] > j)
			DP[i][j] = DP[i-1][j] // if current element has value greater than current sum value then value should be previous one
			else 
			DP[i][j] = DP[i-1][j] OR DP[i-1][j-arr[i-1]]  // if we have already this state or a state with sum value equal to j-arr[i-1] 
			
*/
#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int> &set, int n, int sum){
    
    bool subset[n + 1][sum + 1];
    
    for (int i = 0; i <= n; i++){
        subset[i][0] = true;
    }
    for (int i = 1; i <= sum; i++){
        subset[0][i] = false;
    }
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1]){
                subset[i][j] = subset[i - 1][j];
            }
            if (j >= set[i - 1]){
                subset[i][j] = (subset[i - 1][j] || subset[i - 1][j - set[i - 1]]);
            }
        }
    }
 
    return subset[n][sum];
}
 
int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    if (isSubsetSum(v, n, sum) == true)
        cout<<"Found a subset with given sum";
    else
        cout<<"No subset with given sum";
    return 0;
}
