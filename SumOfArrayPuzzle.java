class SumArrayPuzzle
{
    public static void SumArray(int arr[], int n)
    {
        int leftSum[] = new int[n];
        int rightSum[] = new int[n];
        int Sum[] = new int[n];
 
        int i = 0, j = 0;
 
        /* Left most element of left array is
           always 0 */
        leftSum[0] = 0;
 
        /* Right most element of right array
           is always 0 */
        rightSum[n - 1] = 0;
 
        /* Construct the left array*/
        for (i = 1; i < n; i++)
            leftSum[i] = arr[i - 1] + leftSum[i - 1];
 
        /* Construct the right array*/
        for (j = n - 2; j >= 0; j--)
            rightSum[j] = arr[j + 1] + rightSum[j + 1];
 
        /* Construct the sum array using
        left[] and right[] */
        for (i = 0; i < n; i++)
            Sum[i] = leftSum[i] + rightSum[i];
 
        /*print the sum array*/
        for (i = 0; i < n; i++)
            System.out.print(Sum[i] + " ");
    }
}
