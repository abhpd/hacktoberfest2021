package Java.Algorithms.Searching;

import java.util.*;

class Search {

    public static int linearSearch(int[] arr, int key) {
        int index = -1;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == key) {
                index = i;
                break;
            }
        }
        return index;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Eneter length of array");
        int length = sc.nextInt();
        int[] arr = new int[length];
        System.out.println("Enter array elements");
        for (int i = 0; i < length; i++)
            arr[i] = sc.nextInt();
        System.out.println("Enter element to search");
        int key = sc.nextInt();
        int index = linearSearch(arr, key);
        if (index == -1) {
            System.out.println("Element not found");
        } else {
            System.out.println("Element found at index " + index);
        }
    }
}