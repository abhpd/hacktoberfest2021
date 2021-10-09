
/**
 * Author:  ARUN BALAJI R
 * Date:    23 July 2021 (Friday)
 */


import java.util.*;
public class SmallestMissingPositive{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {1,2,3,4,5};
		System.out.println(s.smallestMissingPositive(arr,arr.length));
	}
}

class Solution{
	//solution 1(worstcase  O(N^2))
	int smallestMissingPositi(int arr[],int n){
		int i;
		for(i=1;i<=n;i++){
			if(!isPresent(arr,i)){
				return i;
			}
		}
		return i;
	}

	boolean isPresent(int arr[],int num){
		for(int i=0;i<arr.length;i++){
			if(arr[i]==num)
				return true;
		}
		return false;
	}

	//solution 2 O(n)
	int smallestMissingPositive(int arr[],int n){
		if(arr==null || arr.length==0)	return 1;
		boolean  containsOne = false;

		//step 1 : replacing -ve elements and elements>n  by '1'
		for(int i=0;i<n;i++){
			if(arr[i]==1){
				containsOne = true;
			}else if(arr[i]<=0 || arr[i]>n){
				arr[i]=1;
			}
		}

		if(!containsOne)	return 1;

		//step 2 : Index referencing (make negative indexs of respecctive elements)
		for(int i=0;i<n;i++){
			int index = Math.abs(arr[i])-1;		//because index starts from 0
			if(arr[index] > 0)	arr[index] = -1 * arr[index];

		}

		//step 3:Traversing and returning first positive or returning n+1
		for(int i=0;i<n;i++){
			if(arr[i]>0)	return i+1;
		}

		return n+1;


		

		
	}
}