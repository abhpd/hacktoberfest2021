package array;

public class Left_Rotation {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[] = {1,2,3,4};
		int n =arr.length;
		System.out.println("Array : ");
	       for(int i = 0; i < n; i++)
	       		System.out.print(arr[i]+" ");
	    System.out.println("\nAfter Left Rotation : ");
	    int res[] = LR(arr);
	    for(int i=0;i<n;i++)
	    	System.out.print(res[i]+" ");
	}
	static int[] LR(int arr[]) {
		int n=arr.length;
		int temp=arr[0];
		for(int i=1;i<n;i++) 
			arr[i-1] = arr[i];
		arr[n-1] = temp;

		return arr;
	}

}
