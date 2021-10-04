package array;

public class check_if_Sorted {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[] = {-21, 1,3, 9}, i=0, n = arr.length;
		if(isSorted(arr,i,n)) System.out.println("Yes it is Sorted");
		else System.out.println("No");
	}
	static boolean isSorted(int arr[],int i, int n) {
		for(i =0;i<n-1;i++) {
			if(arr[i] > arr[i+1])
				return false;
		}
		return true;
	}
	
}
