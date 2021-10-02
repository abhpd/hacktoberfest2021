//Leetcode question : 140. Word Break II

//code : 

class Solution {
public:
    
    void wordBreak_backEng(vector<bool>&dp, int maxLen, int si, int ei, unordered_set<string> &st, string& s, string asf, vector<string> &ans){
        
        if(si >= ei){
            string res = asf.substr(0, asf.size()-1);
            ans.push_back(res);
            return;
        }
        
        for(int l = 1;l<=maxLen && si + l <= ei;l++){
            if(dp[si + l]){
                string sub = s.substr(si, l);
                if(st.find(sub) != st.end()){
                    wordBreak_backEng(dp, maxLen, si + l, ei, st, s, asf + sub + " ", ans);
                }
            }
        }
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int maxLen = 0;
        
        for(string w: wordDict){
            int l = w.size();
            maxLen = max(maxLen, l);
            st.insert(w);
        }
        
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int i=0;i<=n;i++){
            if(!dp[i]) continue;
            
            for(int l = 1;l<=maxLen;l++){
                string w = s.substr(i, l);
                if(st.find(w) != st.end()){
                    dp[i+l] = true;
                }
            }
        }
        
        vector<string> ans;
        if(dp[n]){
            wordBreak_backEng(dp, maxLen, 0, n, st, s, "", ans);
        }
        
        return ans;
    }
};
