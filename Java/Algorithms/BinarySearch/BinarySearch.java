
/**
 * Author:  ARUN BALAJI R
 * Date:    23 August 2021 (Monday)
 */


import java.util.*;
public class BinarySearch{

	/*
	COMPLEXIT : LOG2(N)
	*/


	public static void main(String args[]){
		int[] sortedArr = {-3,-1,0,3,5,7,12,14,17,19,20,34,44,50};
		int[] descArr = {30,29,22,20,18,16,14,11,8,5,3,0,-3,-34};
		int target = 20;
		int result = binarySearch(sortedArr,target);
		System.out.println(result);
		System.out.println(descendingBinarySearch(descArr,target));
	}

	static int binarySearch(int[] sortedArr,int target){
		int start = 0;
		int end = sortedArr.length-1;
		// int mid = start+end /2;
		// what if the range of int exceeds when adding start and end. to avoid thes use below
		
		// return index if not found retunr -1
		while(start<=end){
			int mid = start+(end-start)/2; //both are same but inthis case range of int not exceed
			if(target<sortedArr[mid]){
				end = mid-1;
			}else if(target>sortedArr[mid]){
				start = mid+1;
			}else{
				return mid;
			}
		}
		;

	}

	
	//write binarysearch for desccending order
	static int descendingBinarySearch(int[] arr,int target){
		int start = 0;
		int end = arr.length-1;

		while(start<=end){
			int mid = start+(end-start)/2;
			if(target>arr[mid]){
				end = mid-1;
			}else if(target<arr[mid]){
				start = mid+1;
			}else{
				return mid;
			}
		}
		return -1;

	}
	//NOTE : BINARY SEARCH IS ONLY FOR SORTED ARRAY 
	//Order-Agnostic Binarysearch
	/*
		figure out ascending or descending sorted and apply binary search is called order agnostic binary search
	*/


}
