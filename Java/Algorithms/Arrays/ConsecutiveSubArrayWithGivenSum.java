
/**
 * Author:  ARUN BALAJI R
 * Date:    05 August 2021 (Thursday)
 */


import java.util.*;
public class ConsecutiveSubArrayWithGivenSum{
	public static void main(String args[]){
		int arr[] = {1,4,20,3,10,5};
		Solution s = new Solution();
		System.out.println(s.consecutiveSubArrayWithGivenSum(arr,arr.length,33));
	}
}

class Solution{
	//Sliding Window Technique Solution O(n)
	//note : This works only  for non negative numbers
	boolean consecutiveSubArrayWithGivenSum(int arr[],int n,int sum){
		int curSum = arr[0],start = 0;			
		
		for(int i=1;i<n;i++){					
			while(curSum>sum && start<i-1){		
				curSum-=arr[start];				
				start++;
			}
			if(curSum==sum){					
				return true;
			}
			if(i<n){							
				curSum+=arr[i];					
			}
		}
		return sum==curSum;
	}

	//SAME PROBLEM WITH SLIGHTLY DIFFERENT IMPLEMENTATION

	boolean SubArrayWithGivenSum(int arr[],int n,int targetSum){
		int startWindow=0;
		int curSum = 0;

		for(int windowEnd = 0;windowEnd<n;windowEnd++){
			curSum+=arr[windowEnd];
			while(curSum>targetSum){
				curSum-=arr[startWindow];
				startWindow++;
			}
			if(curSum==targetSum)
				return true;



		}
		return curSum == targetSum;
	}
}