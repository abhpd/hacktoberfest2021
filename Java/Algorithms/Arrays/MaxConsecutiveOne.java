
/**
 * Author:  ARUN BALAJI R
 * Date:    20 July 2021 (Tuesday)
 */


import java.util.*;
public class MaxConsecutiveOne{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {1,1,1,0,1,1,1,1};
		System.out.println(s.getMaxConsecutiveOne(arr,arr.length));
	}
}

class Solution{
	int getMaxConsecutiveOne(int arr[],int n){
		int maxcount=0,count = 0;
		for(int i=0;i<n;i++){
			if(arr[i]==1){
				count++;    //4
			}else{
				maxcount=count;
				count=0;
			}
			maxcount=count;
		}
		return maxcount;
	}
}