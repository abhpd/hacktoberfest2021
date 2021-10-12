
// Yashraj Verma
// https://github.com/yashrajverma

class Knapsack {

    // W is the total weight of the knapsack ,
    // n is the total items in the knapsack.
    // val[] is the value of the corresponding item.
    // wt[] is the weight if the item.

    static int max(int n, int b) {
        return Math.max(n, b);
    }

    static int knapSack(int m, int[] ut, int[] arr, int n) {

        if (n == 0 || m == 0)
            return 0;

        if (ut[n - 1] > m)
            return knapSack(m, ut, arr, n - 1);

        else
            return max(arr[n - 1] + knapSack(m - ut[n - 1], ut, arr, n - 1), knapSack(m, ut, arr, n - 1));
    }

    public static void main(String[] args) {
        int[] val = new int[] { 60, 100, 70 }; // value array.
        int[] wt = new int[] { 10, 20, 30 }; // weight array;
        int W = 50; // total weight of the knapsack.
        int n = val.length; // number of items in knapsack.
        System.out.println(knapSack(W, wt, val, n));
        System.out.println("Yashraj Verma \n 181500832 \n Sec-D");
    }
}
