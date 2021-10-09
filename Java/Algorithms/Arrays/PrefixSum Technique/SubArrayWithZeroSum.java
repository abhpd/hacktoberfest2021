
/**
 * Author:  ARUN BALAJI R
 * Date:    11 August 2021 (Wednesday)
 */


import java.util.*;
public class SubArrayWithZeroSum{

	/*
	Input:
	5
	4 2 -3 1 6

	Output: 
	Yes

	Explanation: 
	2, -3, 1 is the subarray 
	with sum 0.
	*/

	public static boolean  checkZeroSub(int arr[],int n){

		HashSet<Integer> set = new HashSet<Integer>();


		//constructing prefix sum 
		int [] a = new int[n];
		for(int i=1;i<n;i++){
			a[i]+=a[i-1]+arr[i];
		}

		//if the set contains a[i] or a[i] == 0 then it contains zero subarray
		for(int i=0;i<n;i++){
			if(a[i]==0){
				return true;
			}else if(set.contains(a[i])){
				return true;
			}else{
				set.add(arr[i]);
			}
		}

		return false;


	}

	public static void main(String args[]){
		int arr[] = {4,2,-3,1,6};
		System.out.println(checkZeroSub(arr,arr.length)?"YES":"NO");
	}
}