
/**
 * Author:  ARUN BALAJI R
 * Date:    10 August 2021 (Tuesday)
 */


import java.util.*;
public class SumBetweenRange{
	/*
	QUESTION : 
	--------
	Input : 3 7 2 5 8 9
        query(0, 5)
        query(3, 5)
        query(2, 4)
	Output : 34
    	     22
        	 15

	*/
	//	PREFIX SUM TECHNIQue
	public static int query(int[] a,int l,int r){
		//building prefix sum array
		int n = a.length;
		int[] arr = new int[a.length];
		arr[0]=a[0];
		for(int i=1;i<n;i++){
			arr[i]+=(arr[i-1]+a[i]);
		}
		//quring
		if(l==0)
			return arr[r];
		else
			return arr[r]-arr[l-1];
	}

	public static void main(String args[]){
		int[] a = {3,7,2,5,8,9};
		
		System.out.println(query(a,0,5));
		System.out.println(query(a,3,5));
		System.out.println(query(a,2,4));

	}
}