
/**
 * Author:  ARUN BALAJI R
 * Date:    25 July 2021 (Sunday)
 */


import java.util.*;
public class MaxCircularSum{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {8,-4,3,-5,4};
		System.out.println(s.circularSubarraySum(arr,arr.length));
	}
}

class Solution{
	int maxCircularSum(int arr[],int n)
	{	
		
		int res = arr[0];		
		for(int i=0;i<n;i++){	

			int curMax = arr[i];	
			int curSum = arr[i];	
			for(int j=1;j<n;j++){	
				int index = (i+j)%n;
				curSum+=arr[index];		
				curMax= Math.max(curMax,curSum);	
			}
			res = Math.max(res,curMax);	
		}
		return res;

	}

	//this is my implementation but there is slight optimization solution below
	int maxCircularSumKadane(int arr[],int n){
		int minEnd = arr[0];
		int finalMin = arr[0];
		int maxEnd = arr[0];
		int finalMax = arr[0];
		int totalsum = arr[0];
		int result = -1;
		for(int i=1;i<n;i++){

			//finding max of subarray using kadanes
			maxEnd = Math.max(maxEnd+arr[i],arr[i]);
			finalMax = Math.max(finalMax,maxEnd);

			//for finding max of circular subarray
				//1. finding minumum of normal subarray using kadanes
				//2. subtract it from total sum of array gives maxx of circular subarray
			//1
			minEnd = Math.min(arr[i]+minEnd,arr[i]);
			finalMin = Math.min(minEnd,finalMin);

			//2
			totalsum+=arr[i];



		}
		result = Math.max(finalMax,(totalsum-finalMin));
		return result;

	}


	int circularSubarraySum(int arr[],int n){
		//step 1: finding normal max sum in subarray
		int max_normal = findNormalMaxSubarray(arr,n);
		if(max_normal<0)	return max_normal;

		//finding max in circular subarray
		//Its similar tto previous approach but here instead of calculating minsum using kadane , we just invert arrayelements
		//and apply the same kadane max which gives us the same.
		int arr_sum = 0;
		for(int i=0;i<n;i++){
			arr_sum+=arr[i];
			arr[i]=-arr[i];
		}
		//here we inverted and again call same funcciton to get min array and add it to the arr_sum

		int max_circular = arr_sum+findNormalMaxSubarray(arr,n);
		return Math.max(max_circular,max_normal);

	}

	int findNormalMaxSubarray(int arr[],int n){
		int maxEnd = arr[0];
		int finalMax= arr[0];
		for(int i=1;i<n;i++){
			maxEnd = Math.max(maxEnd+arr[i],arr[i]);
			finalMax = Math.max(finalMax,maxEnd);
		}
		return  finalMax;
	}

}