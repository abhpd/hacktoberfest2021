import java.util.*;

public class Reverse {

    public static void reverseArray(int[] arr) {
        int low = 0, high = arr.length - 1;
        while (low < high) {
            arr[low] = arr[low] + arr[high];
            arr[high] = arr[low] - arr[high];
            arr[low] = arr[low] - arr[high];
            low++;
            high--;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of array");
        int n = scanner.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        reverseArray(array);
        for (int x : array) {
            System.out.print(x + " ");
        }
    }
}
