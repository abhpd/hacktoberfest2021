using System;

namespace Sorting
{
	class BubbleSort
	{
		static void bubbleSort(int[] arr, int n)
		{
			int i, j, temp;
			bool swapped;
			for (i = 0; i < n - 1; i++)
			{
				swapped = false;
				for (j = 0; j < n - i - 1; j++)
				{
					if (arr[j] > arr[j + 1])
					{
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
						swapped = true;
					}
				}

				// IF no two elements were
				// swapped by inner loop, then break
				if (swapped == false)
					break;
			}
		}

		static void printArray(int[] arr, int size)
		{
			int i;
			for (i = 0; i < size; i++)
				Console.Write(arr[i] + " ");
			Console.WriteLine();
		}

		// Driver method
		public static void Main()
		{
			int[] arr = { 26, 32, 10, 90, 64, 34, 25, };
			int n = arr.Length;
			bubbleSort(arr, n);
			printArray(arr, n);
		}

	}
}