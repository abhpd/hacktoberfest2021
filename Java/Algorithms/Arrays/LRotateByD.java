
/**
 * Author:  ARUN BALAJI R
 * Date:    06 July 2021 (Tuesday)
 */


import java.util.*;
public class LRotateByD{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {1,2,3,4,5};
		System.out.println("Before rotation");
		s.printArray(arr);
		s.leftRotateByReversalAlgo(arr,2);
		System.out.println("After rotation");
		s.printArray(arr);
	}
}

class Solution{
	//method 1 : by calling leftrotatebyone for d times
	void rotateleftbyD(int arr[],int d){
		for(int i=1;i<=d;i++)
			leftRotateByOne(arr);
	}

	//method2: 

	void roteteleftbyDbetter(int arr[],int d){
		int temp[] = new int[d];
		for(int i=0;i<d;i++)
			temp[i]=arr[i];
		for(int i=d;i<arr.length;i++){
			arr[i-d]=arr[i];
		}
		for(int i=0;i<d;i++){
			arr[arr.length-d+i]=temp[i];
		}
	}

	//best solution
	//method  3;Reversal algorthhm
	static void leftRotateByReversalAlgo(int a[],int d){
		int len = a.length;
		reverse(a,0,d-1);
		reverse(a,d,len-1);
		reverse(a,0,len-1);
	}

	static void reverse(int arr[],int low,int high){
		while(low<high){
			//swap
			arr[low] = arr[low]+arr[high];
			arr[high] = arr[low]-arr[high];
			arr[low]=arr[low]-arr[high];
			low++;
			high--;
		}
	}


	static void leftRotateByOne(int a[]){
		int n = a.length;
		int temp = a[0];
		for(int i=0;i<n-1;i++){
			a[i]=a[i+1];
		}
		a[n-1]=temp;
	}

	void  printArray(int arr[]){
		for(int i:arr){
			System.out.print(i+"  ");
		}
		System.out.println();
	}

}