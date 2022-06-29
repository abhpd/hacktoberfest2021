//https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==1) return s;
        string ans = "";
        // low and high points to the starting & ending indices of the pallindromic substrings 
        int low, high;
        // starting index of the max length pallindromic substring
        int start_index;
        // max length of the pallindromic substring
        int max_length = 0;
        for(int i = 1; i < n; i++)
        {
            // for odd length substrings
            // choose i as epicenter and move left and right checking the string is pallindrome or not
            low = i - 1;
            high = i + 1;
            while(low >= 0 && high < n && s[low] == s[high])
            {
                if(max_length < high - low + 1)
                {
                    max_length = high - low + 1;
                    start_index = low;
                }
                --low;
                ++high;
            }
            // for even length substrings
            // choose i-1 and i as epicenters and move left and right checking the string is pallindrome or not
            low = i - 1;
            high = i;
            while(low >= 0 && high < n && s[low] == s[high])
            {
                if(max_length < high - low + 1)
                {
                    max_length = high - low + 1;
                    start_index = low;
                }
                --low;
                ++high;
            }
        }
        // if there is no pallindromic substring present of size >= 2 
        if(max_length == 0)
        {
            ans += s[0];
            return ans;
        }
        for(int i = start_index; i < start_index + max_length; i++)
        {
            ans += s[i];
        }
        return ans;
    }
};
