import java.util.Arrays;
 
class Main
{
    public static void swap(int[] arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
 
    // Recursive function to perform selection sort 
    public static void selectionSort(int[] arr, int i, int n)
    {
        // find the minimum element in the unsorted subarray `[i…n-1]`
        // and swap it with `arr[i]`
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            // if `arr[j]` is less, then it is the new minimum
            if (arr[j] < arr[min])
            {
                min = j;    // update the index of minimum element
            }
        }
 
        // swap the minimum element in subarray `arr[i…n-1]` with `arr[i]`
        swap(arr, min, i);
 
        if (i + 1 < n) {
            selectionSort(arr, i + 1, n);
        }
    }
 
    public static void main(String[] args)
    {
        int[] arr = { 3, 5, 8, 4, 1, 9, -2 };
 
        selectionSort(arr, 0, arr.length);
 
        // print the sorted array
        System.out.println(Arrays.toString(arr));
    }
}






