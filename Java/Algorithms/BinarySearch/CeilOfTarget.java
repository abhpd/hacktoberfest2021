
/**
 * Author:  ARUN BALAJI R
 * Date:    24 August 2021 (Tuesday)
 */


import java.util.*;
public class CeilOfTarget{
	
	public static void main(String args[]){
		int arr[] = {2,6,8,10,12};
		System.out.println(findCeil(arr,7));
		
	}

	public static int findCeil(int[] arr,int target){
		int start = 0;
		int end = arr.length-1;
		while(start<=end){
			
			int mid = start+(end-start)/2;

			if(target>arr[mid]){
				start = mid+1;
			}else if(target<arr[mid]){
				end = mid-1;
			}else{
				return arr[mid];
			}


		}

		//similarly we can return floor of target by giving arr[end]
		/*
		Logic : while (start<=end ) is violated their ordder is like [end,mid,start]
		so we return start for floor and end for floor
		*/
		return arr[start];
	}


}