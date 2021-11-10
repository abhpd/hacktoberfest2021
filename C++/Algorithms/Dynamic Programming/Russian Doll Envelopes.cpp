// LEETCODE QUESTION :  Russian Doll Envelopes  (https://leetcode.com/problems/russian-doll-envelopes/)

// code : 
class Solution {
public:
    static bool mycomp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){
            return a[1] <  b[1];
        }
        return a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(), mycomp);
        
        int envp = 0;
        int n = envelopes.size();
        
        vector<int> dp(n, 0);
        for(int i=0;i<n;i++){
            dp[i] = 1;
            for(int j=i-1;j>=0;j--){
                if(envelopes[i][1] > envelopes[j][1] && envelopes[i][0] > envelopes[j][0]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            envp = max(dp[i], envp);
        }
        
        return envp;
    }
};
