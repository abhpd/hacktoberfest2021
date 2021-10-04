package array;
import java.util.Arrays;

public class Search {
	public static void main(String ar[]) {
	int arr[] = {2,1,7,4,9,6};
	int  x = 4;
	int res = LinearSearch(arr, x);
	if(res == -1) 
		System.out.println("Not found");
	else
		System.out.println("Element found at "+res);
	
	}
	static int LinearSearch(int arr[], int x) {
		int n =arr.length;
		for(int i=0; i<n; i++) {
			if(arr[i] == x)
				return i;
		}
		return -1;
	}
	static int binarySearch(int arr[], int x) {
		int n=arr.length;
		Arrays.sort(arr);
		int l=0,r=n-1,mid;
		while(l<r) {
			mid = (l+r)/2;
			if(x == arr[mid])
				return mid;
			else if(x<arr[mid])
				r = mid-1;
			else
				l = mid+1;
		}
		return -1;
	}
}
