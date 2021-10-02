package RadixSort;

class RadixSort {

    public static void main(String[] args) {
        RadixSort test = new RadixSort();
        int[] ArrayToBeSorted = { -9, -1, 10, -2, 12, 102, -3, 12, 39, 8, 2, 6 };
        System.out.println("Original Array: ");
        for (int i = 0; i < ArrayToBeSorted.length; i = i + 1) {
            System.out.print(ArrayToBeSorted[i] + " ");
        }

        test.rsort(ArrayToBeSorted, 10);

        System.out.println("\n\nSorted Array: ");
        for (int i = 0; i < ArrayToBeSorted.length; i = i + 1) {
            System.out.print(ArrayToBeSorted[i] + " ");
        }

        System.out.print("\n");
    }

    // The sort function
    public void rsort(int[] A, int r) {
        if (A.length == 0) {
            return;
        }

        // Minimum and Maximum values
        int min = A[0];
        int max = A[0];

        for (int ctr = 0; ctr < A.length; ++ctr) {
            if (A[ctr] < min)
                min = A[ctr];
            else if (A[ctr] > max)
                max = A[ctr];

        }

        /*
         * Perform counting sort on each exponent or digit, starting at the least
         * significant digit
         */
        int exp = 1;
        for (; (max - min) / (exp) >= 1;) {
            RadixSort.countSort(A, r, exp, min);
            exp = exp * r;
        }
    }

    public static void countSort(int[] Arr, int r, int exp, int min) {
        int bucket;
        int[] buckets = new int[r];
        int[] output = new int[Arr.length];

        // Initialize bucket
        for (int ctr = 0; ctr < r; ctr++) {
            buckets[ctr] = 0;
        }

        // Count Frequencies
        for (int ctr = 0; ctr < Arr.length; ctr++) {
            bucket = (int) (((Arr[ctr] - min) / exp) % r);
            buckets[bucket]++;
        }

        // Compute cumulates
        for (int i = 1; i < r; i = i + 1) {
            buckets[i] += buckets[i - 1];
        }

        // Move the records
        for (int i = Arr.length - 1; i >= 0; i = i - 1) {
            bucket = (int) (((Arr[i] - min) / exp) % r);
            output[--buckets[bucket]] = Arr[i];
        }

        // Copy back to the original array
        for (int i = 0; i < Arr.length; i = i + 1) {
            Arr[i] = output[i];
        }
    }
}