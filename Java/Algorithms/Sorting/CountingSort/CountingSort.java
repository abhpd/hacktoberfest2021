import java.util.Arrays;

public class CountingSort {
	/*
         * Sorts an array using counting sort
	 * @param arr[]    Array of elements
	 * @param size     Size of array
	 */
	public static void countSort(int arr[], int size) {
	    int[] output = new int[size+1]; // Initialize output array
	    // Find the largest element of the array
	    int Max = arr[0];
	    for (int i = 1; i < size; i++) {
	    	Max = Math.max(Max, arr[i]);
	    }
	    // Initialize frequency array to all zeroes
	    int[] freq = new int[Max+1]; 
	    Arrays.fill(freq, 0); 
	    // Store the frequency of each element
	    for (int i = 0; i < size; i++) {
	    	freq[arr[i]]++;
	    }
	    // Store the prefix frequency of each element
	    for (int i = 1; i <= Max; i++) {
	    	freq[i] += freq[i - 1];
	    }
	    // Find index of element in frequency array, and place in the output array
	    for (int i = size-1; i >= 0; i--) {
	    	output[freq[arr[i]]-1] = arr[i];
	    	freq[arr[i]]--;
	    }
	    // Copy array into output
	    for (int i = 0; i < size; i++) {
	        arr[i] = output[i];
	    }
	}
    /*
     * Main method to test counting sort method
     */
    public static void main(String args[])
    {
    	int[] data = {2, 4, 1, 5, 7, 2, 6}; // Array (can be modified)
        int size = data.length; // Size of array
        countSort(data, size); // Sort the array
        // Print out the sorted array
        System.out.println("Sorted array: ");
        System.out.println(Arrays.toString(data));
    }
}
