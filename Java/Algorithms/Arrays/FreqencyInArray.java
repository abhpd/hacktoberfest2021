
/**
 * Author:  ARUN BALAJI R
 * Date:    09 July 2021 (Friday)
 */


import java.util.*;
public class FreqencyInArray{
	public static void main(String args[]){
		Solution s = new Solution();
		// int arr[]= {10,10,10,25,30,30};
		int arr[] = {40,50,50,50};
		s.getFrequency(arr);
	}
}


class Solution{
	void getFrequency(int arr[]){
		int count = 1;
		int elem=0;
		for(int i=1;i<arr.length;i++){
			if(arr[i]==arr[i-1]){
				count++;
			}else{
				System.out.println(arr[i-1]+" "+count);
				count=1;

			}
			elem = arr[i];
		}
		System.out.println(elem + " "+count);

		
		
	}
}