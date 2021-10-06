
/**
 * Author:  ARUN BALAJI R
 * Date:    02 July 2021 (Friday)
 */


import java.util.*;
public class ArrayDeletion{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {1,2,3,4,5,6};
		s.deleteLast(arr);
		s.printArray(arr);
		s.deleteStart(arr);
		s.printArray(arr);
		s.deleteAt(arr,2);
		s.printArray(arr);
	}
}

class Solution{
	void deleteLast(int arr[]){
		arr[arr.length-1]=0;
	}

	void deleteStart(int arr[]){
		// arr[0]=0;
		for(int i=0;i<arr.length-1;i++){
			arr[i]=arr[i+1];
		}
	}

	void deleteAt(int arr[],int pos){
		for(int i=0;i<=arr.length-1;i++){
			if(i==pos){
				arr[i]=arr[i+1];
				return;
			}

		}
	}

	void printArray(int arr[]){
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" ");
		System.out.println();
		
	}
}