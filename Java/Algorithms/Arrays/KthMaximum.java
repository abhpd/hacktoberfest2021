import java.util.*;

public class KthMaximum {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long t = sc.nextLong();
		while(t-- > 0) {
			int n = sc.nextInt();
			int k = sc.nextInt();
			long[] ar = new long[n];
			long max = -1;
			for(int i = 0 ; i < n ; i++) {
				ar[i] = sc.nextLong();
				max = Math.max(max, ar[i]);
			}
			long ans = 0;
			for(int i = k - 1 ; i < n ; i++) {
				if(ar[i] == max) {
					ans += (n - i);
				}
			}
			System.out.println(ans);
		}
		sc.close();
	}

}
