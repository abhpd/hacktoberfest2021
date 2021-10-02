// LEETCODE QUESTION : Coin Change (https://leetcode.com/problems/coin-change/)

// CODE : 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> dp(amount + 1, INT_MAX);
        
        dp[0] = 0;
        for(int target = 1 ; target <= amount ; target++){
            for(int &ele: coins){
                if(target - ele >= 0){
                    dp[target] = min(dp[target - ele] + 1, dp[target]);
                }
            }
        }

        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};
