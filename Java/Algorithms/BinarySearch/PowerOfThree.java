import java.io.*; 
import java.util.*; 


class PowerOfThree {

	// 3^40 > 10^18// log(10^18)(base3) = 40;
	static int size = 40;
	static long p[] = new long[size];
	static long sum[] = new long[size];

	public static long solve(long n){
		if(n <= 0){
			return 0;
		}
		long ans = 0;
		for(int i = 0; i < size; i++){
			if(sum[i] >= n){
				ans = p[i] + solve(n - p[i]);
				break;
			}
		}
		return ans;
	}

	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		p[0] = 1;
		sum[0] = 1;
		for(int i = 1; i < size; i++){
			p[i] = 3*p[i-1];
			sum[i] = sum[i-1] + p[i];
		}
		int t = sc.nextInt();
		while(t-- > 0){
			long n = sc.nextLong();
			System.out.println(solve(n));
		}

	}
}
