
/**
 * Author:  ARUN BALAJI R
 * Date:    30 July 2021 (Friday)
 */


import java.util.*;
public class MinGroupFlip{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[]= {1,1,0,0,0,1};
		s.minGroupflip(arr,arr.length);
	}
}

class Solution{
	void minGroupflip(int arr[],int n){
		for(int i=1;i<n;i++){
			if(arr[i]!=arr[i-1]){
				if(arr[i]!=arr[0]){
					System.out.print("From "+i+" to ");
				}else{
					System.out.println(i-1);
				}
			}
		}
		if(arr[n-1]!=arr[0]){
			System.out.println(n-1);
		}


		
	}
}