
/**
 * Author:  ARUN BALAJI R
 * Date:    23 July 2021 (Friday)
 */


import java.util.*;
public class MaxLenOfOddEvenSubArray{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {10,12,8,4};
		System.out.println(s.maxLen(arr,arr.length));
	}
}

class Solution{
	int maxLen(int arr[],int n){
		int len = 1;
		int res = 1;
		for(int i=0;i<n-1;i++){
			if((arr[i]%2==0 && arr[i+1]%2!=0) || (arr[i]%2!=0 && arr[i+1]%2==0)){
				len++;
			}else{
				res = Math.max(res,len);
				len=1;
			}
		}
		return res;
	}
}