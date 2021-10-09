//Java program  to find a triplet that sum to a given value
import java.util.*;

class TripletSum {
 //Approach using hashing
	static boolean find3Sum(int A[],int n, int sum)
	{
		
		for (int i = 0; i < n - 2; i++) {

			// Find pair in subarray A[i+1..n-1]
			// with sum equal to sum - A[i]
			HashSet<Integer> s = new HashSet<Integer>();
			int curr_sum = sum - A[i];
			for (int j = i + 1; j < n; j++)
			{
				if (s.contains(curr_sum - A[j]))
				{
					System.out.println("Triplet is "+ A[i]+ " "+ A[j]+ " "+ (curr_sum - A[j]));
					return true;
				}
				s.add(A[j]);
			}
		}

		// If we reach here, then no triplet was found
		return false;
	}

	public static void main(String[] args)
	{
		int A[] = { 1, 4, 45, 6, 10, 8 };
		int sum = 22;
		int n = A.length;

		find3Sum(A, n, sum);
	}
}
