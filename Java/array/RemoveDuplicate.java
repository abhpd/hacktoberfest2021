package array;

import java.util.Arrays;

public class RemoveDuplicate {

	public static void main(String[] args) {
		int arr[]= {1,2,3,4,2,2,4};
		int n=arr.length;
		System.out.println("Array : ");
		Arrays.sort(arr);
		for(int i=0;i<n;i++)
			System.out.print(arr[i]+" ");
		System.out.println("\nAfter Removing Duplicated : ");
		int res[]=remDuplicate(arr);
		int n2=res.length;
		for(int i=0;i<n2;i++)
			System.out.print(res[i]+" ");
		
//		System.out.println("\nNaive");
//		int res2=naive(arr);
//		for(int i=0;i<res2;i++)
//			System.out.print(arr[i]+" ");
		
		System.out.println("\nBest");
		int res3=best(arr);
		for(int i=0;i<res3;i++)
			System.out.print(arr[i]+" ");
	}
	static int[] remDuplicate(int arr[]){
		int n=arr.length;
		int b[] = new int[n],k=0;
		for(int i=0;i<n-1;i++) {
			if(arr[i]!=arr[i+1]) {
				if(i==0) {	
					b[k]=arr[0]; 
					k++; }
				b[k]=arr[i+1];
				k++;
				 }
		}
		return b;
	} ///////////////////// Using Temporary Array
	static int naive(int arr[]) {
		int n=arr.length,res=1;
		int temp[] = new int[n];
		temp[0]=arr[0];
		for(int i=1;i<n;i++) {
			if(temp[res-1] != arr[i]) {
				temp[res]= arr[i];
				res++;
			}
		}
		for(int i=0;i<res;i++) {
			arr[i]=temp[i];
		}
		return res;
	}
	///////////////////////////////////////////////////////////////////////
	static int best(int arr[]) {
		int n=arr.length,res=1;
		for(int i=1;i<n;i++) {
			if(arr[i]!=arr[res-1])
			{
				arr[res]=arr[i];
				res++;
			}
		}
		return res;
	}
}
