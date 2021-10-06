
/**
 * Author:  ARUN BALAJI R
 * Date:    10 August 2021 (Tuesday)
 */


import java.util.*;
public class MaxOccInteger{
	/*
	Input:
	n = 4
	L[] = {1,4,3,1}
	R[] = {15,8,5,4}
	Output: 4
	Explanation: The given ranges are [1,15]
	 [4, 8] [3, 5] [1, 4]. The number that 
	is most common or appears most times in 
	the ranges is 4.
	*/

	//NAIVE APPROACH

	public static int maxoccInteger(int L[],int R[],int n){
		int max = Integer.MIN_VALUE;
		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
		for(int i=0;i<n;i++){
			for(int j=L[i];j<=R[i];j++){
				map.put(j,map.getOrDefault(j,0)+1);
			}
		}
		// System.out.println(map.toString());

		for(Integer i:map.values()){
			
			max = Math.max(i,max);

	}
	return max;
	}


	public static int prefixSumMaxOccur(int L[],int R[],int n){
		int MAX = 1000000;
		int[] arr = new int[MAX];

		int maxi = -1;
		for(int i=0;i<n;i++){
			arr[L[i]]++;
			arr[R[i]+1]--;
			//finding max right most element
			maxi = Math.max(maxi,R[i]);
		}


		//finding prefix sum and index
		int maxOccur = arr[0];
		int ind = 0;
		for(int i=1;i<MAX;i++){
			arr[i]+=arr[i-1];
			if(arr[i]>maxOccur){
				maxOccur = arr[i];
				ind = i;
			}

		}
		return ind;
		
	}

	public static void main(String args[]){
		int l[]={1,4,3,1};
		int r[] = {15,8,5,4};
		int n = 4;
		System.out.println(prefixSumMaxOccur(l,r,n));

	}
		}
