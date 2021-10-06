
/**
 * Author:  ARUN BALAJI R
 * Date:    27 July 2021 (Tuesday)
 */


import java.util.*;
public class RearrangeWithoutXtraspace{
	public static void main(String args[]){
		Solution s = new Solution();
		int[] arr = {4,0,2,1,3};
		s.arrangeArray(arr,arr.length);
	}
}

/*
CONCEPT :
a=a+b*b
in first traversal we encrypt number using above formula(here we can get old vaue of a using %n)
in second traversal we decrypt number by dividing by n 

*/
class Solution{
	void arrangeArray(int arr[],int n){
		for(int i=0;i<n;i++){
			arr[i]=arr[i]+(arr[(int)arr[i]]%n)*n;
		}
		for(int i=0;i<n;i++){
			arr[i]=arr[i]/n;
		}
		//print rearranged 
		for(int i:arr){
			System.out.print(i+" ");
		}		
	}
}