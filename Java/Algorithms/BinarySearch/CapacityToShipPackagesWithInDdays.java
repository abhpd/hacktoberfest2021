// Problem Link : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
    public int shipWithinDays(int[] wt, int days) {
        int max = 0;
        int sum = 0;
        for(int val : wt) {
            sum += val;
            max = Math.max(max, val);
        }
        if(wt.length == days) {
            return max;
        }
        int low = max;
        int high = sum;
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(isPossible(wt, mid, days) == true) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
    public static boolean isPossible(int[] wt, int mid, int days) {
        int d = 1;
        int sum = 0;
        for(int i = 0; i<wt.length; i++) {
            sum += wt[i];
            if(sum > mid){
                d++;
                sum = wt[i];
            }
        }
        return d<=days;
    }
}
