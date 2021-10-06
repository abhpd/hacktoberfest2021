
/**
 * Author:  ARUN BALAJI R
 * Date:    09 July 2021 (Friday)
 */
/*
	DYNAMIC PROGRAMMING 
	It is a proccess of makeing our algorithm effficient by storing repetitive tasks 
	and use it instead of everytime computing it. Mostly used in repetitive functions
*/


/*
	FIBONACCI SERIES
	1,1,2,3,5,8,12...

*/
import java.util.*;
public class FibonacciNumber{
	public static void main(String args[]){
		Solution s = new Solution();
		System.out.println(s.FibonacciEff(6));
	}
}

class Solution{
	//computing nth fibonacci term
	public int Fibonacci(int n){
		int result = 0;
		if(n==1 || n==2){
			result = 1;
		}else{
			//here i calculate fib everytime
			result = Fibonacci(n-1)+Fibonacci(n-2);
		}
		return result;
	}

	public int FibonacciEff(int n){
		int arr[] = new int[n+1];
		if(n==1 || n==2)
			return 1;
		arr[1]=1;arr[2]=1;  //[1,1] for stroing computing values
		for(int i=3;i<=n;i++){
			// here i store calculated fibo in array
			arr[i] = arr[i-1] + arr[i-2];
		}
		return arr[n];

	}
}