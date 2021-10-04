package array;

public class Max_difference_in_Order {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[] = {28,10,35,3,8};
		int n = arr.length;
		System.out.println("Array : ");
	       for(int i = 0; i < n; i++)
	    	   System.out.print(arr[i]+" ");
	       
		int res=maxDiff(arr);
		System.out.println("\nMax Difference : "+res);
	}
	static int maxDiff(int arr[]) {
		int n=arr.length, res=arr[1]-arr[0], minVal = arr[0];
		for(int i=1;i<n;i++) {
			res = Math.max(res, arr[i]-minVal);
			minVal = Math.min(minVal, arr[i]);
		}
		return res;
	}

	//naive solution
	static int naive_maxDiff(int arr[]) {
		int n = arr.length, res = arr[1]-arr[0];
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n-1;j++)
				res = Math.max(res, arr[j]-arr[i]);
		return res;
	}
}
