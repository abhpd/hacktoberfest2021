
/**
 * Author:  ARUN BALAJI R
 * Date:    03 August 2021 (Tuesday)
 */


import java.util.*;
public class MaxSumOfKConsecutive{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {1,8,30,-5,20,7};
		int arr1[] = {5,-10,6,90,3};
		System.out.println(s.maxSumOfKConsecutiveSlidingWind(arr,arr.length,3));
	}
}

class Solution{

	//APPROACH 1 : Considering eacch element as 1st element and traverse upto k
	//O(n^2)

	int maxSumOfKConsecutiveNaive(int arr[],int n,int k){
		int maxSum = -1;					
		for(int i=0;i<n-k;i++){				
			int sum=0;						
			for(int j=i;j<(i+k);j++){		
				sum+=arr[j];				
			}
			maxSum = Math.max(sum,maxSum);	
		}
		return maxSum;
	}


	//O(n)  Sliding window technique
	//APPROACH 2: to traverse up to k and find currentsum
	//			  then after each element we have to subtract first element fo windows and add next element of window

	int maxSumOfKConsecutiveSlidingWind(int arr[],int n,int k){
		int currentSum = 0;
		int maxSum = 0;
		//step 1 : calculating sum upto k
		for(int i=0;i<k;i++){
			currentSum+=arr[i];
		}
		//step 2 : calculating by subtracting prev and add next for each element
		maxSum = currentSum;
		for(int i=k;i<n;i++){
			currentSum+=(arr[i]-arr[i-k]);
			maxSum = (currentSum>maxSum) ? currentSum : maxSum;
		}
		return maxSum;

	}




}