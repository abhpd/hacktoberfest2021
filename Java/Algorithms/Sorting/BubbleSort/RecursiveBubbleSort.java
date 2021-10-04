//Recursive implementation of Bubble sort in java

import java.util.Arrays;

public class RecursiveBubbleSort
{
	// Main Method
	public static void main(String[] args)
	{
		int arr[] = {78,-2,338,29,0,11};
	
		sort(arr, arr.length);
		
		System.out.println("Sorted array : ");

		for(int i=0;i<arr.length;i++){
		System.out.println(arr[i]);
		};
	}


	// A function to implement bubble sort
	static void sort(int array[],int n)
	{
		// This is our base case
		if (n==1)
			return;
	
		// In every pass, one of the greatest element moves to end
		for (int i=0;i<n-1;i++)
			if (array[i]>array[i+1])
			{
				//Swaping
				int temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
			}
		//Recur remaining unsorted elements
		sort(array, n-1);
	}
	
}
