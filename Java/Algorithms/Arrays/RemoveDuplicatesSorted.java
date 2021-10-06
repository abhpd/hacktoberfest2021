
/**
 * Author:  ARUN BALAJI R
 * Date:    03 July 2021 (Saturday)
 */


import java.util.*;
public class RemoveDuplicatesSorted{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[]= {10,20,20,30,30,30};
		System.out.println("Before removing duplicates");
		s.printArray(arr);
		//removeing dupicates
		s.removeDuplicates(arr);


		System.out.println("After removing duplicates");
		s.printArray(arr);
	}
}

class Solution{
	void removeDuplicates(int arr[]){
		int temp[] = new int[arr.length];
		temp[0]=arr[0];
		int size = 1;
		for(int i=1;i<arr.length;i++){
			if(arr[i]!=temp[size-1]){
				temp[size]=arr[i];
				size++;	
			}
		}

		for(int i=0;i<arr.length;i++){
			arr[i] = temp[i];
		}
	}

	void printArray(int arr[]){
		for(int i:arr){
			System.out.print(i+" ");

		}
		System.out.println();
	}
}