package array;

public class Min_Consecutive_Flips {

	public static void main(String[] args) {
		int arr[] = {0,1,0,0};
		System.out.println("Array : ");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println("\nMin Consecutive Flips : ");
		minFlip(arr);
	}
	static void minFlip(int arr[]) {
		int ele;
		int c0=0,c1=0;
		//to find which consecutive element Subarray is less appearing
		for (int i = 0; i < arr.length; i++) {
			 
		}
		if(c0>c1)	ele = 1;
		else		ele = 0;
		System.out.println("Element : "+ele);
		// to print positions
		for (int i = 0; i < arr.length; i++) {
			if(arr[i]== ele) {
				System.out.println("From "+i);
				break;
			}
			
		}
		
	}

}
