// https://leetcode.com/problems/guess-number-higher-or-lower/
class Solution {
public:
    int guessNumber(int n) {
        int s=1;
        int e=n;int mid=-1;int ans=0;
        while(s<=e)
        {
            mid=s+(-s+e)/2;
            if(guess(mid)==0)
            {return mid;}
            else if(guess(mid)==-1)
                e=mid-1;
            else if(guess(mid)==1)
                s=mid+1;
        }
        return ans;
    }
};
