class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        
        int ans = 1;
        int st = 0;
        
        ///fill all substring of length 1
        for(int i=0; i<n; i++){
            dp[i][i] = true;
        }
        
        ///fill all substring of length 2
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                ans = 2;
                dp[i][i+1] = true;
                st = i;
            }
            else{
                dp[i][i+1] = false;
            }
        }
        
        //dp[i][j] means start at i and end at j...
         ///fill the rest of the table
        for(int l=3; l<=n; l++){  //for substring of length 3 and more...
            for(int i=0; i<=n-l; i++){       //n-l is the max index where index of                                                        //particular substring of length l end
                int end = i+l-1;
                
                if(s[i] == s[end]){
                    dp[i][end] = dp[i+1][end-1];
                    if(dp[i][end] == true){
                        ans = l;
                        st = i;
                    }
                }
                else{
                    dp[i][end] = false;
                }
            }
        }
        //printing the substring
        return s.substr(st, ans);
    }
};
