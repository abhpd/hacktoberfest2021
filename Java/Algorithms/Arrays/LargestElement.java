
/**
 * Author:  ARUN BALAJI R
 * Date:    02 July 2021 (Friday)
 */


import java.util.*;
public class LargestElement{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {2,5,2,8,4,12,56,43,78,99,23,123,45};
		System.out.println(s.indexOfLargeElement(arr));
		System.out.println(s.largeElement(arr));
	}
}

class Solution{
	
	int indexOfLargeElement(int arr[]){
		int max = arr[0];
		for(int i=0;i<arr.length-1;i++){
			if(arr[i]<arr[i+1])
				max = i+1;
			
		}
		return max;
	}

	int largeElement(int arr[]){
		int max = arr[0];
		for(int i=0;i<arr.length-1;i++){
			if(arr[i]<arr[i+1])
				max = arr[i+1];
		}
		return max;
	}
}