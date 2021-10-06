
/**
 * Author:  ARUN BALAJI R
 * Date:    09 August 2021 (Monday)
 */
//SLIDING WINDOW TECHNIQUE

/*
Example 1:

Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is 
{4, 45, 6}

Example 2:
Input:
A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Explanation:
Minimum length subarray is {10}
*/

import java.util.*;
public class SmallestSubArrayGivenSum{

	static int smallestSubArraySize(int arr[],int n,int targetSum){
		int minSubarraySize = Integer.MAX_VALUE;
		int curSum = 0;
		int windowStart = 0;
		for(int windowEnd = 0;windowEnd<n;windowEnd++){
			curSum+=arr[windowEnd];

			while(curSum>targetSum){
				minSubarraySize = Math.min(minSubarraySize,windowEnd-windowStart+1);
				curSum-=arr[windowStart];
				windowStart++;
			}

		}
		return minSubarraySize;
	}

	//driver code
	public static void main(String args[]){
		int arr[] = {1, 4, 45, 6, 0, 19};
		int ans = smallestSubArraySize(arr,arr.length,51);
		System.out.println(ans);

	}
}

