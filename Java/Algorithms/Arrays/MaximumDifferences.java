//maximum value of arr[j]=arr[i] in such a way that j>i

/**
 * Author:  ARUN BALAJI R
 * Date:    08 July 2021 (Thursday)
 */


import java.util.*;
public class MaximumDifferences{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {30,10,8,2};
		System.out.println(s.getMaxDifferenceEff(arr));
	}
}

class Solution{
	

	int getMaxDifferences(int arr[]){
		int max = arr[arr.length-1]-arr[arr.length-2];

		for(int i=arr.length-1;i>=0;i--){
			for(int j=i-1;j>=0;j--){
				
				max = Math.max(max,arr[i]-arr[j]);
			}
		}
		return max;
	}
	//here the idea is we just run loop onec along that we also track min value(because manimum value gives max difference)
	//and updating min values  along with them

	int getMaxDifferenceEff(int arr[]){
		int max = arr[1]-arr[0];
		int min = arr[0];
		for(int j=1;j<arr.length;j++){
			max = Math.max(max,arr[j]-min);
			min = Math.min(min,arr[j]);
		}
		return max;
	}
}