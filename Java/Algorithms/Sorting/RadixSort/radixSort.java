import java.util.*;
import java.lang.*;
import java.io.*;

class RadixSorting {
    int RANGE = 9;

    public int getMax(int[] arr, int n){
        int max = arr[0];

        for(int i = 1; i < n; i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }

        return max;
    }

    public void countsort(int[] arr, int n, int d) {
        int[] output = new int[n];
        int[] count = new int[RANGE+1];

        for(int i = 0; i < n; i++) {
            count[arr[i]/d % 10] += 1;
        }

        for(int i = 1; i <= RANGE; i++) {
            count[i] += count[i-1];
        }

        for(int i = n-1; i >= 0; i--) {
            output[count[arr[i]/d % 10]-1] = arr[i];
            count[arr[i]/d % 10] -= 1;
        }

        for(int i = 0; i < n; i++){
            arr[i] = output[i];
        }
    }

    public void radixsort(int[] arr, int n) {
        int max = getMax(arr, n);

        for(int d = 1; max/d > 0; d *= 10) {
            countsort(arr, n, d);
        }
    }
}

public class radixSort{
    public static void main(String[] args) {
        RadixSorting ob = new RadixSorting();
        int[] arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
        int n = arr.length;
        ob.radixsort(arr, n);
        System.out.println("After sorting");
        for(int item:arr) {
        	System.out.print(item+" ");
        }
        System.out.println();
    }
}