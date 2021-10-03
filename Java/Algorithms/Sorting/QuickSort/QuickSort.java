/* Quick Sort */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {

	public int partition(int[] arr, int start, int end) {
		int pIndex = start;
		int pivot = arr[end];
		for (int i = start; i < end; i++) {
			if (arr[i] <= pivot) {
				int temp = arr[i];
				arr[i] = arr[pIndex];
				arr[pIndex] = temp;
				pIndex++;
			}
		}
		int temp = arr[pIndex];
		arr[pIndex] = arr[end];
		arr[end] = temp;
		return pIndex;
	}

	public void quickSort(int arr[], int start, int end) {
		if(start < end) {
			int pIndex = partition(arr, start, end);
			quickSort(arr,start, pIndex-1);
			quickSort(arr, pIndex + 1, end);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(br.readLine());
		int[] arr = new int[num];
		for (int i = 0; i < num; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		Solution obj = new Solution();
		obj.quickSort(arr, 0, num-1);
		for (int i = 0; i < num; i++) {
			System.out.print(arr[i] + " ");
		}
	}
}
