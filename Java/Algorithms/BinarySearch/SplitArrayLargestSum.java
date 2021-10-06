class SplitArrayLargestSum{
	// https://leetcode.com/problems/split-array-largest-sum/
	/*
	Input: nums = [7,2,5,10,8], m = 2
	Output: 18
	Explanation:
	There are four ways to split nums into two subarrays.
	The best way is to split it into [7,2,5] and [10,8],
	where the largest sum among the two subarrays is only 18.
	*/
	public static void main(String args[]){
		Solution s = new Solution();
		int[] arr = {7,2,5,10,8};
		int m=2;
		int ans = s.splitArray(arr,m);
		System.out.println(ans);

	}




}

class Solution {
    public int splitArray(int[] nums, int m) {
        int start = 0;
        int end = 0;
        
        //finding start and end
        for(int i=0;i<nums.length;i++){
            start = Math.max(start,nums[i]);
            end+=nums[i];
        }
        
        //now we have a range . applying binarySearch
        while(start < end){
            int mid = start+(end-start)/2;
            
            int sum = 0;
            int pieces = 1;
            for(int num:nums){
                if(sum + num > mid){
                    
                    sum = num;
                    pieces++;
                }else{
                    sum += num;
                }
            
            }
            
            if(pieces>m){
                start = mid+1;
            }else{
                end = mid;
            }
            
            
        }
        
        return end;
        
    
    }
}