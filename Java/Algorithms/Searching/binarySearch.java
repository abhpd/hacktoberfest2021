package Java.Algorithms.Searching;

import java.util.*;

public class binarySearch {

    public static int binarySearching(int[] arr, int key) {
        int index = -1;
        int start = 0, last = arr.length - 1;
        while (start <= last) {
            int mid = start + (last - start) / 2;
            if (arr[mid] == key) {
                index = mid;
                break;
            } else if (arr[mid] < key)
                start = mid + 1;
            else
                last = mid - 1;
        }
        return index;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Eneter length of array");
        int length = sc.nextInt();
        int[] arr = new int[length];
        System.out.println("Enter array elements in sorted order (non-decreasing)");
        for (int i = 0; i < length; i++)
            arr[i] = sc.nextInt();
        System.out.println("Enter element to search");
        int key = sc.nextInt();
        int index = binarySearching(arr, key);
        if (index == -1) {
            System.out.println("Element not found");
        } else {
            System.out.println("Element found at index " + index);
        }
    }
}
