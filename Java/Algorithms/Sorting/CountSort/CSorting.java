package sorting;

import java.util.Scanner;

public class CSorting {
    static void countSort(int n, int... arr){
        //1.Find out the maximum element (let it be max) from the given array.
        int max=0;
        for(int i=0;i< arr.length;i++){
            if(max<arr[i]){
                max=arr[i];
            }

        }
        //2.Initialize an array of length max+1 with all elements 0.
        // This array is used for storing the count of the elements in the array.
        int[] count= new int[max+1];

        //3.Store the count of each element at their respective index in count array.
        for(int i=0;i<arr.length;i++) {
            count[arr[i]]++;
        }
        //4.Store cumulative sum of the elements of the count array.
        // It helps in placing the elements into the correct index of the sorted array.
        for(int i=1;i<count.length;i++){
            count[i]=count[i]+count[i-1];
        }
        //5.Find the index of each element of the original array in count array, and
        // place the elements in output array
        int[] arr_sorted= new int[n];
        for(int i=n-1; i>=0; i--) {
            arr_sorted[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }
        //6.Copy the sorted elements into original array
        System.out.println("SORTED ARRAY :");
        for(int i=0; i<n; i++){
            arr[i]=arr_sorted[i];
            System.out.print(" "+arr[i]);
        }

    }
    public static void main(String[] args) {
        //ALL ABOUT COUNT SORTING
        // Counting sort is a sorting algorithm that sorts the elements of an array by counting
        // the number of occurrences of each unique element in the array.The count is stored in
        // an auxiliary array and the sorting is done by mapping the count as an index of the
        // auxiliary array.

        // Time complexity: O(n+k) [n= no.of elements, k= range of input]

        // Counting sort is used when:
        //1.there are smaller integers with multiple counts.
        //2.linear complexity is the need.

        Scanner sc= new Scanner(System.in);
        System.out.println("SORTING USING COUNT SORT:");
        System.out.print("Enter the number of elements of required array :");
        int n= sc.nextInt();
        int[] arr= new int[n];
        System.out.println("Enter the array(enter only positive integer):");
        for(int i =0; i<n; i++){
            arr[i]=sc.nextInt();

        }
        countSort(n,arr);

    }
}
