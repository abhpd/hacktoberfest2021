import java.util.*;

public class MaxDiff {

    public int findDiff(int[] arr) {

        int n = arr.length;
        if (n == 2)
            return arr[1] - arr[0];
        if (n < 2)
            return 0;
        int res = arr[1] - arr[0];
        int min_val = arr[0];
        for (int i = 1; i < n; i++) {
            res = Math.max(res, arr[i] - min_val);
            min_val = Math.min(min_val, arr[i]);
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of array");
        int n = scanner.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        MaxDiff max = new MaxDiff();
        System.out.println("The maximum difference is " + max.findDiff(array));

    }
}
