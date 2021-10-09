
/**
 * Author:  ARUN BALAJI R
 * Date:    10 August 2021 (Tuesday)
 */


import java.util.*;
public class EquillibriumPoint{

	public static int equilibriumPoint(int[] arr,int n){
		//computing prefix sum
		int[] a = new int[n];
		a[0]=arr[0];
		for(int i=1;i<n;i++){
			a[i]+=(a[i-1]+arr[i]);
		}

		System.out.println(Arrays.toString(a));
		return 0;
	}


	public static void main(String args[]){
		int arr[] = {4,2,-2};
		System.out.println(equilibriumPoint(arr,arr.length));
	}
}