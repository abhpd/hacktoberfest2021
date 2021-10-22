// Dynamic Programming Java implementation of Matrix
// Chain Multiplication.
// See the Cormen book for details of the following
// algorithm
import java.util.*;
class matrixChainMultiplication
{

	
	
    static int MatrixChainOrder(int arr[],int N)
    {   int t[][]=new int[N][N];
        for(int i=0; i<N; i++){
            Arrays.fill(t[i],-1);
        }
        int res = hel(arr,1,N-1,t);
        return res;
    }
    
    static int hel(int a[],int l, int h,int t[][]){
        if(l>=h){
            return 0;
        }
        if(t[l][h]!=-1){
            return t[l][h];
        }
        int temp = Integer.MAX_VALUE;
        for( int i=l; i<h; i++){
            temp = Math.min(temp,(a[l-1]*a[h]*a[i])+hel(a,l,i,t)+hel(a,i+1,h,t));
        }
        return t[l][h]=temp;
    }
	// Driver code
	public static void main(String args[])
	{
		int arr[] = new int[] { 1, 2, 3, 4 };
		int size = arr.length;

		System.out.println(
			"Minimum number of multiplications is "
			+ MatrixChainOrder(arr, size));
	}
}
/* This code is contributed by Harmanjeet Singh*/
