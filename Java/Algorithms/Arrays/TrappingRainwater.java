
/**
 * Author:  ARUN BALAJI R
 * Date:    20 July 2021 (Tuesday)
 */


import java.util.*;
public class TrappingRainwater{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {3,0,0,2,0,4};
		System.out.println(s.getUnitOfWater(arr,arr.length));
	}
}

class Solution{
	int getUnitOfWater(int arr[],int n){
		int quantity = 0;
		for(int i=1;i<n-1;i++){
			int lmax = arr[i];
			for(int j=0;j<i;j++){
				lmax = Math.max(lmax,arr[j]);
			}
			int rmax = arr[i];
			for(int j=i+1;j<n;j++){
				rmax = Math.max(rmax,arr[j]);
			}

			quantity+=Math.min(lmax,rmax)-arr[i];
		}
		return quantity;
	}
}