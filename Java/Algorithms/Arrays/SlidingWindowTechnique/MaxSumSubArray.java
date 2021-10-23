
/**
 * Author:  ARUN BALAJI R
 * Date:    09 August 2021 (Monday)
 */


import java.util.*;
public class MaxSumSubArray{
	public static void main(String args[]){

		Solution s = new Solution();
		int arr[] = {1,8,30,-5,20,7};
		int arr1[] = {5,-10,6,90,3};
		System.out.println(s.maxSumSubArray(arr,arr.length,3));	}
}

class Solution{
	//Same sliding window technique

	int maxSum = Integer.MIN_VALUE;	
	int curSum = 0;
	int maxSumSubArray(int arr[],int n,int k){
		for(int i=0;i<n;i++){
			if(i<k){
				curSum+=arr[i];
			}else{
				curSum+=(arr[i]-arr[i-k]);
				maxSum = Math.max(maxSum,curSum);
			}
		}
		return maxSum;
	}
}