
/**
 * Author:  ARUN BALAJI R
 * Date:    25 August 2021 (Wednesday)
 */


import java.util.*;
public class SearchInInfinite{
	public static void main(String args[]){
		int[] arr= {0,1,2,3,4,5,6,7,8,9};
		System.out.println(searchTarget(arr,5));

		
	}


	public static int searchTarget(int[] arr,int x){
		int start = 0;
		int end = 1;
		while(x>arr[end]){
			int tempStart = end+1;
			//end = prev end + sizeof box*2(using  old start)
			end = end+(end-start+1)*2;
			start = tempStart;
		}
		return binarySearch(arr,x,start,end);
	}

	static int binarySearch(int[] sortedArr,int target,int start,int end){
		while(start<=end){
			int mid = start+(end-start)/2;
			if(target<sortedArr[mid]){
				end = mid-1;
			}else if(target>sortedArr[mid]){
				start = mid+1;
			}else{
				return mid;
			}
		}
		return -1;

	}
	
}