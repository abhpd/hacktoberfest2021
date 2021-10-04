class KadanesAlgorithm{
    public static int kadane(int[] A)
    {
        int maxSoFar = 0;
        int maxEndingHere = 0;
 
        for (int i: A)
        {
            maxEndingHere = maxEndingHere + i;
            maxEndingHere = Integer.max(maxEndingHere, 0);
            maxSoFar = Integer.max(maxSoFar, maxEndingHere);
        }
 
        return maxSoFar;
    }
 
    public static void main(String[] args)
    {
        int[] A = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        System.out.println("The sum of contiguous subarray with the " +
                            "largest sum is " + kadane(A));
    }
}