package array.Sliding_Window_Technique;

public class Sliding_Window_Technique {
	
// Maximum sum of subArray in K window
	
	public static void main(String[] args) {
		int arr[] = {1,-2,6,9,-4,3}, k=3;
		System.out.println("Array : ");
		for (int i = 0; i < arr.length; i++) 
			System.out.print(arr[i]+" ");
		System.out.println("\nMax Sum is "+max_sum(arr, k));
		
	}
	static int max_sum(int arr[],int k) {
		int sum=0, max=0;
		for (int i = 0; i < k; i++) {
			sum += arr[i];
		}
		max = sum;
		for (int i = k; i < arr.length; i++) {
			sum += arr[i]-arr[i-k];
			max = Math.max(max, sum);
		}
		return max;
}
}