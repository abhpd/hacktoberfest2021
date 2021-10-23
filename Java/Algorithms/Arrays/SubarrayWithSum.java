
/**
 * Author:  ARUN BALAJI R
 * Date:    19 July 2021 (Monday)
 */


import java.util.*;
public class SubarrayWithSum{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {1,2,3,7,5};

		System.out.println(s.subArray(arr,arr.length,12));	
	}
}

class Solution{
	static ArrayList<Integer> subArray(int arr[],int n,int s){
		ArrayList<Integer> al = new ArrayList<Integer>();
		int i=0,j=0,sum=0;

		while(sum!=s){				//13!=12
			if(sum < s && i<n){		//13<12 && 4<5
				sum+= arr[i++];		//sum= 13
			}
			else if(sum > s && j<n){	//13>12 && 0<n
				sum-=arr[j++];			//sum=12 j=0
			}else{
				al.add(-1);
				return al;
			}
		}
		al.add(j+1);
		al.add(i);
		return al;

	}
}