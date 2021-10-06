
/**
 * Author:  ARUN BALAJI R
 * Date:    06 July 2021 (Tuesday)
 */


import java.util.*;
public class LRotateByOne{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {1,2,3,4,5};
		System.out.println("Array  before rotation");
		s.printArray(arr);
		s.leftRotateByOne(arr);
		System.out.println("Array after rotation");
		s.printArray(arr);
	}
}

class Solution{
	void leftRotateByOne(int a[]){
		int n = a.length;
		int temp = a[0];
		for(int i=0;i<n-1;i++){
			a[i]=a[i+1];
		}
		a[n-1]=temp;
	}

	void  printArray(int arr[]){
		for(int i:arr){
			System.out.print(i+"  ");
		}
		System.out.println();
	}
}