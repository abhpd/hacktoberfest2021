
/**
 * Author:  ARUN BALAJI R
 * Date:    23 August 2021 (Monday)
 */


import java.util.*;
public class OrderAgnosticBinarySearch{
	//Order-Agnostic Binarysearch
	/*
		figure out ascending or descending sorted and apply binary search is called order agnostic binary search
	*/
	static int orderAgnosticBinarySearch(int[] arr,int target){
		int start = 0;
		int end = arr.length -1;
		boolean isAscending = arr[start] < arr[end];
		while(start<=end){
			int mid = start + (end - start)/2;
			if(target==arr[mid]){
				return mid;
			}

			if(isAscending){
				if(target < arr[mid])
					end = mid-1;
				else
					start = mid+1;	
			}else{
				if(target < arr[mid])
					start = mid+1;
				else
					end = mid-1;	
			}
			
			
			
		}
		return -1;
	}

	public static void main(String args[]){
		int[] ascenArr = {-9,-1,3,5,8,34,56};
		int[] desArr = {34,23,22,20,18,15,10,3,2,1};
		System.out.println(orderAgnosticBinarySearch(ascenArr,3));
		System.out.println(orderAgnosticBinarySearch(desArr,3));
	}
}