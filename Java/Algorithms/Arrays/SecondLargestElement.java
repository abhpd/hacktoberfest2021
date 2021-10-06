
/**
 * Author:  ARUN BALAJI R
 * Date:    02 July 2021 (Friday)
 */


import java.util.*;
public class SecondLargestElement{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {12,12,12,7};
		System.out.println(s.secondLargestElement(arr));
	}
}

class Solution{
	int secondLargestElement(int arr[]){
		int max = 0;
		int secMax = -1;
		for(int i=0;i<arr.length;i++){
			if(arr[i]>arr[max]){
				secMax = arr[max];
				max = arr[i];
			}
			else if(arr[i]!=arr[max]){
				if(secMax == -1 || arr[i]>arr[secMax]){
					secMax = arr[i];
				}
			}
			
		}

		return secMax;
		
		

	}
}


