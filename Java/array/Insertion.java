package array;

public class Insertion {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int cap = 10;
		int arr[]= new int[cap];
		arr[0]=12;
		arr[1]=2;
		arr[2]=54;
		int n=3, x=7, pos = 2;
		
		for(int i=0;i<n;i++)
			System.out.print("\t"+arr[i]);
		
		int n2 = insertArray(arr, n, x, cap, pos);
		
		System.out.println("\nAfter");
		for(int i=0;i<n2;i++)
			System.out.print("\t"+arr[i]);
	}
	static int insertArray(int arr[], int n, int x, int cap, int pos) {
		if(n==cap)
			return n;
		int idx = pos-1;
		for(int i=n-1;i>=idx;i--)
			arr[i+1] = arr[i];
		arr[idx] = x;
		return (n+1);
	}

}
