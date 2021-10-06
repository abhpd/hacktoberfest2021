
/**
 * Author:  ARUN BALAJI R
 * Date:    02 July 2021 (Friday)
 */


import java.util.*;
public class SearchUnsortedArray{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {2,4,6,3,4,6};
		System.out.println(s.searchElement(arr,93));
		
	}
}

class Solution{
	int searchElement(int arr[],int x){
		for(int i=0;i<arr.length;i++){
			if(arr[i]==x){
				return i+1;
			}
		}
		return -1;
	}
}

//o(n)

//if its a sorted array we reduce this by using binary searcch O(log n)

