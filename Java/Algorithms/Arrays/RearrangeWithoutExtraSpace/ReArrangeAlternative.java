
/**
 * Author:  ARUN BALAJI R
 * Date:    27 July 2021 (Tuesday)
 */


import java.util.*;
public class ReArrangeAlternative{
	public static void main(String args[]){
		Solution s = new Solution();
		int[] arr = {1,2,3,4,5,6};
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
		int max = n-1;
		int min = 0;
		//using formula a=a+b*n
		//N is always greater than a and b
		int N = arr[max]+1;
		for(int i=0;i<n;i++){
			if(i%2==0){
				arr[i]=(arr[max]%N)*N + arr[i]; 
				max--;
			}else{
				arr[i]=(arr[min]%N)*N + arr[i];
				min++;
			}
		}
		for(int i=0;i<n;i++){
			arr[i]=arr[i]/N;
		}
		// print rearranged 
		for(int i:arr){
			System.out.print(i+" ");
		}		
	}
}