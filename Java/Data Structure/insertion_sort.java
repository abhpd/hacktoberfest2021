class InsertionSort {
    void sort(int arr[])
    {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int m = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > m) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = m;
        }
    }static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");

        System.out.println();
    }public static void main(String args[])
    {
        int arr[] = { 34, 1, 130, 15, 6 };
        InsertionSort ob = new InsertionSort();
        ob.sort(arr);
        printArray(arr);
    }
}
