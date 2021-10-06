
/**
 * Author:  ARUN BALAJI R
 * Date:    04 July 2021 (Sunday)
 */


import java.util.*;
public class MoveZerosToEnd{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {20,0,0,0,0,20}; 
		
		
		s.moveZerosToEnd(arr);
		s.printArray(arr);


	}
}


class Solution{
	void moveZerosToEnd(int arr[]){
		
		int count = 0;
		for(int i=0;i<arr.length;i++){
			if(arr[i]!=0){
				arr[count++]=arr[i];
				
			}
		}

		while(count<arr.length)
			arr[count++]=0;


	}




	static void printArray(int arr[]){
		for(int i:arr){
			System.out.print(i+" ");
		
		}
		System.out.println();
	}
}