
/**
 * Author:  ARUN BALAJI R
 * Date:    06 August 2021 (Friday)
 */


import java.util.*;
public class NbonacciNumbers{
	public static void main(String args[]){
		Solution s = new Solution();
		s.printNbonacciNum(3,8);
		s.printNbonacciNum(4,10);
	}
}


class Solution{
	/*
	The idea is based on sliding window.
	 The current term a[i] can be computed as a[i-1] + a[i-1] – a[i-n-1]
	 Note: in implementation instead of computing a[i-1]+a[i-1], multiplied with 2
	*/
	 void printNbonacciNum(int n,int m){
	 	//initialize empty array (automatically filled with zero)
	 	int[] arr = new int[m];

	 	//filling 1 for n and n-1 th element
	 	arr[n]=1;
	 	arr[n-1]=1;

	 	for(int i=n+1;i<m;i++){
	 		arr[i] = (2*arr[i-1])-arr[i-n-1];
	 	}

	 	System.out.println(Arrays.toString(arr));
	 }
}



