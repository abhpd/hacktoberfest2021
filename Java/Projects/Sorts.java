//Consolidated program to enter an array and choose the type of sort you wish to perform
//Bahukhandi93
//Pull request for data structures (1D arrays) and sorts


import java.util.Arrays;
import java.util.Scanner;

public class sort {
    private static int n;  //size of the 1D array
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("\f"); //clear console
        System.out.println("Enter the size of 1D array:");
        n = sc.nextInt(); //enter size of 1D array
        double[] OrArray = new double[n]; //declaring double 1D array of size n 

        System.out.println("Enter 1D array of " + n + " size: "); 
        for (int i = 0; i < n; i++)
            OrArray[i] = sc.nextDouble(); //Entering elements of 1d array


        System.out.println("Choose the sort you wish to perform: \n1.Selection sort\n2.Insertion sort\n3.Merge sort\n4.Quick sort\n5.Bubble sort\n6.Shell sort\n7.Radix sort(Only for integer values)\n8.Heap sort\n9.Comb sort\n10.End");
        int a = sc.nextInt(); //entering our choice of sort

        System.out.println("\n\nThe original array:"); //display the original array
        display(OrArray);

        switch (a) {   //switch case to choose type of sort the user wishes to perform
            case 1:
                SelecionSort(OrArray);
                break;
            case 2:
                InsertionSort(OrArray);
                break;
            case 3:
                MergeSort(OrArray,0,n-1);
                break;
            case 4:
                QuickSort(OrArray,0,n-1);
                break;
            case 5:
                BubbleSort(OrArray);
                break;
            case 6:
                ShellSort(OrArray);
                break;
            case 7:
                RadixSort(OrArray);
                break;
            case 8:
                HeapSort(OrArray);
                break;
            case 9:
                CombSort(OrArray);
                break;
            case 10: break;
            default: System.out.println("Invalid input! Please start again! :(");
                    break;
        }
        System.out.println("\n\nThe sorted array:");
        display(OrArray);
    }

    static void CombSort(double[] orArray) {
        int gap = n;

        // Initialize swapped as true to make sure that
        // loop runs
        boolean swapped = true;

        // Keep running while gap is more than 1 and last
        // iteration caused a swap
        while (gap != 1 || swapped == true)
        {
            // Find next gap
            gap = getNextGap(gap);

            // Initialize swapped as false so that we can
            // check if swap happened or not
            swapped = false;

            // Compare all elements with current gap
            for (int i=0; i<n-gap; i++)
            {
                if (orArray[i] > orArray[i+gap])
                {
                    // Swap arr[i] and arr[i+gap]
                    double temp = orArray[i];
                    orArray[i] = orArray[i+gap];
                    orArray[i+gap] = temp;

                    // Set swapped
                    swapped = true;
                }
            }
        }
    }  //Comb sort

    private static int getNextGap(int gap) //accompanying method to Comb sort
    {
        gap = (gap*10)/13;
        if (gap < 1)
            return 1;
        return gap;
    }

    static void HeapSort(double[] orArray) {
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(orArray, n, i);

        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            double temp = orArray[0];
            orArray[0] = orArray[i];
            orArray[i] = temp;

            // call max heapify on the reduced heap
            heapify(orArray, i, 0);
        }
    } //Heap sort

    private static void heapify(double[] orArray, int n, int i) {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (l < n && orArray[l] > orArray[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < n && orArray[r] > orArray[largest])
            largest = r;

        // If largest is not root
        if (largest != i) {
            double swap = orArray[i];
            orArray[i] = orArray[largest];
            orArray[largest] = swap;

            // Recursively heapify the affected sub-tree
            heapify(orArray, n, largest);
        }
    } //accompanying method for Heap sort

    static void RadixSort(double[] orArray)// Radix sort
    {
        // Find the maximum number to know number of digits
        double m = getMax(orArray, n);

        // Do counting sort for every digit. Note that
        // instead of passing digit number, exp is passed.
        // exp is 10^i where i is current digit number
        for (int exp = 1; m / exp > 0; exp *= 10)
            countSort(orArray, n, exp);
    }

    private static void countSort(double[] orArray, int n, int exp) //accompanying method to Radix sort
    {
        int output[] = new int[n]; // output array
        int i;
        int count[] = new int[10];
        Arrays.fill(count, 0);

        // Store count of occurrences in count[]
        for (i = 0; i < n; i++)
            count[(int) ((orArray[i] / exp) % 10)]++;

        // Change count[i] so that count[i] now contains
        // actual position of this digit in output[]
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        for (i = n - 1; i >= 0; i--) {
            output[count[(int) ((orArray[i] / exp) % 10)] - 1] = (int) orArray[i];
            count[(int) ((orArray[i] / exp) % 10)]--;
        }

        // Copy the output array to arr[], so that arr[] now
        // contains sorted numbers according to current digit
        for (i = 0; i < n; i++)
            orArray[i] = output[i];
    }

    private static double getMax(double[] orArray, int n) //accompanying method to  Radix sort
    {
        double mx = orArray[0];
        for (int i = 1; i < n; i++)
            if (orArray[i] > mx)
                mx = orArray[i];
        return mx;
    }

    static void ShellSort(double[] orArray) //Shell sort
    {
        for (int gap = n/2; gap > 0; gap /= 2)
        {
            // Do a gapped insertion sort for this gap size.
            // The first gap elements a[0..gap-1] are already
            // in gapped order keep adding one more element
            // until the entire array is gap sorted
            for (int i = gap; i < n; i += 1)
            {
                // add a[i] to the elements that have been gap
                // sorted save a[i] in temp and make a hole at
                // position i
                double temp = orArray[i];

                // shift earlier gap-sorted elements up until
                // the correct location for a[i] is found
                int j;
                for (j = i; j >= gap && orArray[j - gap] > temp; j -= gap)
                    orArray[j] = orArray[j - gap];

                // put temp (the original a[i]) in its correct
                // location
                orArray[j] = temp;
            }
        }
    }

    static void BubbleSort(double[] orArray)// Bubble sort
    {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (orArray[j] > orArray[j + 1]) {
                    // swap arr[j+1] and arr[j]
                    double temp = orArray[j];
                    orArray[j] = orArray[j + 1];
                    orArray[j + 1] = temp;
                }
            }
        }
    }

    static void QuickSort(double[] orArray,int low, int high)//Quick sort
    {
        if (low < high)
        {

            // pi is partitioning index, arr[p]
            // is now at right place
            int pi = partition(orArray, low, high);

            // Separately sort elements before
            // partition and after partition
            QuickSort(orArray, low, pi - 1);
            QuickSort(orArray, pi + 1, high);
        }
    }

    private static int partition(double[] orArray, int low, int high) //accompanying method to Quick sort
    {
        // pivot
        double pivot = orArray[high];

        // Index of smaller element and
        // indicates the right position
        // of pivot found so far
        int i = (low - 1);

        for(int j = low; j <= high - 1; j++)
        {

            // If current element is smaller
            // than the pivot
            if (orArray[j] < pivot)
            {

                // Increment index of
                // smaller element
                i++;
                double temp = orArray[i];
                orArray[i] = orArray[j];
                orArray[j] = temp;
            }
        }
        double temp = orArray[i+1];
        orArray[i+1] = orArray[high];
        orArray[high] = temp;
        return (i + 1);
    }

    static void MergeSort(double[] orArray,int l, int r) //Merge sort
    {
        if (l < r) {
            // Find the middle point
            int m =l+ (r-l)/2;

            // Sort first and second halves
            MergeSort(orArray, l, m);
            MergeSort(orArray, m + 1, r);

            // Merge the sorted halves
            merge(orArray, l, m, r);
        }
    }

    private static void merge(double[] orArray, int l, int m, int r)//accompanying method to Merge sort
    {
        // Find sizes of two subarrays to be merged
        int n1 = m - l + 1;
        int n2 = r - m;

        /* Create temp arrays */
        double L[] = new double[n1];
        double R[] = new double[n2];

        /*Copy data to temp arrays*/
        for (int i = 0; i < n1; ++i)
            L[i] = orArray[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = orArray[m + 1 + j];

        /* Merge the temp arrays */

        // Initial indexes of first and second subarrays
        int i = 0, j = 0;

        // Initial index of merged subarray array
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                orArray[k] = L[i];
                i++;
            }
            else {
                orArray[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy remaining elements of L[] if any */
        while (i < n1) {
            orArray[k] = L[i];
            i++;
            k++;
        }

        /* Copy remaining elements of R[] if any */
        while (j < n2) {
            orArray[k] = R[j];
            j++;
            k++;
        }
    }

    static void InsertionSort(double[] orArray)//Insertion sort
    {
        for (int i = 1; i < n; ++i) {
            double key = orArray[i];
            int j = i - 1;

            /* Move elements of arr[0..i-1], that are
               greater than key, to one position ahead
               of their current position */
            while (j >= 0 && orArray[j] > key) {
                orArray[j + 1] = orArray[j];
                j = j - 1;
            }
            orArray[j + 1] = key;
        }
    }


    static void  SelecionSort(double[] OrArray) //selection sort
    {
        for (int i = 0; i < n-1; i++)
        {
            // Find the minimum element in unsorted array
            int min_idx = i;
            for (int j = i+1; j < n; j++)
                if (OrArray[j] < OrArray[min_idx])
                    min_idx = j;

            // Swap the found minimum element with the first
            // element
            double temp = OrArray[min_idx];
            OrArray[min_idx] = OrArray[i];
            OrArray[i] = temp;
        }
    }

    static void display(double[] Arr) //display the array
    {
        for (int i=0; i<n;i++)
            System.out.print(Arr[i]+"\t");
    }
}
