// C# program for implementation of Selection Sort
using System;

class SelectionSort
{
	static void selectionSort(int[] arr)
	{
		int n = arr.Length;

		// One by one move boundary of unsorted subarray
		for (int i = 0; i < n - 1; i++)
		{
			// Find the minimum element in unsorted array
			int min_idx = i;
			for (int j = i + 1; j < n; j++)
				if (arr[j] < arr[min_idx])
					min_idx = j;

			// Swap the found minimum element with the first element
			int temp = arr[min_idx];
			arr[min_idx] = arr[i];
			arr[i] = temp;
		}
	}

	// A utility function to print the array
	static void printArray(int[] arr)
	{
		int n = arr.Length;
		for (int i=0; i<n; ++i)
			Console.Write(arr[i]+" ");
		Console.WriteLine();
	}

	public static void Main()
	{
		int []arr = {95,7,64,45,11};
		selectionSort(arr);
		Console.WriteLine("Sorted array");
		printArray(arr);
	}

}
