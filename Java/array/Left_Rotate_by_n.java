package array;

public class Left_Rotate_by_n {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[] = {1,2,3,4,5,6},d=4;
		int n =arr.length;
		System.out.println("Array : ");
	       for(int i = 0; i < n; i++)
	       		System.out.print(arr[i]+" ");
	    System.out.println("\nAfter Left Rotation : ");
	    int res[] = best_LR(arr,d);
	    for(int i=0;i<n;i++)
	    	System.out.print(res[i]+" ");
	}
	///best take n time but 1 space
	static int[] best_LR(int arr[],int d) {
		int n = arr.length;
		reverse(arr,0,d-1); // reverse 0-d 
		reverse(arr,d,n-1); // reverse d-n
		reverse(arr,0,n-1); // reverse 0-n  then we get correct ans
		return arr;
	}
	static int[] reverse(int arr[],int l,int r) {
		int temp;
		while(l<r) {
			temp = arr[l];
			arr[l]=arr[r];
			arr[r]=temp;
			l++;
			r--;
		}
		return arr;
	}
	///// good it take n time and d space
	static int[] LR(int arr[], int d) {
		int n = arr.length ;	
		int b[]=new int[d];
		for(int i=0;i<d;i++)
			b[i]=arr[i];
		
		for(int i=d;i<n;i++) 
			arr[i-d]=arr[i];
	
		int count=0;
		for(int i=n-d;i<n;i++) {
			arr[i]= b[count];
			count++;
		}
		
		return arr;
	}
	
}
