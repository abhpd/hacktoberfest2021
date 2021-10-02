import java.util.*;

class MCM {
    static int matrixMultiplication(int N, int arr[]) {
        // code here
        int t[][] = new int[N + 1][N + 1];
        for (int a[] : t)
            Arrays.fill(a, -1);
        return memo(arr, 1, N - 1, t);
    }

    public static int memo(int arr[], int i, int j, int t[][]) {

        if (i >= j) {
            t[i][j] = 0;
            return 0;
        }
        if (t[i][j] != -1)
            return t[i][j];
        int minVal = Integer.MAX_VALUE;

        for (int k = i; k < j; k++) {
            int temp = memo(arr, i, k, t) + memo(arr, k + 1, j, t) + (arr[i - 1] * arr[k] * arr[j]);

            minVal = Math.min(minVal, temp);

        }
        t[i][j] = minVal;
        return minVal;

    }

    public static void main(String args[]) {
        int arr[] = { 10, 30, 5, 60 };
        System.out.println(matrixMultiplication(arr.length, arr));
    }

}