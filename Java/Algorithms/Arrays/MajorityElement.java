
/**
 * Author:  ARUN BALAJI R
 * Date:    29 July 2021 (Thursday)
 * 
 */


import java.util.*;
public class MajorityElement{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[]={20,30,40,50,50,50,50};
		System.out.println(s.findMajorityEff(arr,arr.length));
	}
}

class Solution{
	int findMajority(int arr[],int n){
		//O(n^2)
		int count = 1;
		int majoritylim = n/2;	//3
		
		
		for(int i=0;i<n;i++){			//i=1
			for(int j=i+1;j<n;j++){		//j=4
				if(arr[i]==arr[j]){		//7=7
					count++;			//c=3
				}
				if(count>majoritylim)	return i;
			}
		}
		return -1;
	}

	//O(n)
	int findMajorityEff(int arr[],int n){
		//phase 1 : to find which might be majority
		int count = 1,res = 0;
		for(int i=0;i<n;i++){
			if(arr[res]==arr[i]){
				count++;
			}else{
				count--;
			}
			if(count==0){
				res = i;
				count=1;
			}
		}

		//phsase 2:Deciding thee res element is majority or not
		count=0;
		for(int i=0;i<n;i++){
			if(arr[res]==arr[i]){
				count++;
			}
		}
		if(count<=n/2){
			res = -1;
		}

		return res;
	}
}