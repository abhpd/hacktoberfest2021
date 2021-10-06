
/**
 * Author:  ARUN BALAJI R
 * Date:    03 July 2021 (Saturday)
 */


import java.util.*;
public class IsSortedArray{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {100,20,200};
		
		System.out.println(s.isSorted(arr) ? "Yes" : "No");
	}
}


class Solution{
	public boolean isSorted(int arr[]){
		if(arr.length==1) return true;
		for(int i=0;i<arr.length;i++){
			if(arr[i]<=arr[i+1])
				return true;
			else
				return false;
			

		}
		return false;
	}
}