
/**
 * Author:  ARUN BALAJI R
 * Date:    21 July 2021 (Wednesday)
 */


import java.util.*;
public class MaxSumSubArray{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[]= {1,-2,3,-1,2};
		System.out.println(s.getMaxKadanesAlgo(arr,arr.length));

	}
}
//Practice both methods well.
class Solution{
	int getMaxSumsubarray(int arr[],int n){
		int res = arr[0];
		for(int i=0;i<n;i++){
			int cur = 0;
			for(int j=i;j<n;j++){
				cur+=arr[j];
				res = Math.max(cur,res);
			}
		}
		return res;
	}
	//Kadane's Algorithm
	
	int getMaxKadanesAlgo(int arr[],int n){
		int res = arr[0];
		int maxEnd = arr[0];
		for(int i=1;i<n;i++){
			maxEnd = Math.max(maxEnd+arr[i],arr[i]);
			res = Math.max(res,maxEnd);
		}
		return res;
	}
}