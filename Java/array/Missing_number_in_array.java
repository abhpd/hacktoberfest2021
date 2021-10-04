package array;
import java.io.*;
public class Missing_number_in_array {
	public static void main(String[] args) throws IOException {
		BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(rd.readLine().trim());
		while(t --> 0) {
			int n=Integer.parseInt(rd.readLine().trim());
			String[] str = rd.readLine().trim().split(" ");
			int array[] = new int[n-1];
			for(int i=0;i<n-1;i++)
				array[i] = Integer.parseInt(str[i]);
		Solution sol = new Solution();
		System.out.println(sol.MissingNumber(array, n));
		}
	}
}
class Solution {
    int MissingNumber(int array[], int n) {
        int i=0,sum=0;
        int sum_N = n*(n+1)/2;
        for(i=0;i<n-1;i++){
            sum+=array[i];
        }
        
        return sum_N-sum;
    }
    
}