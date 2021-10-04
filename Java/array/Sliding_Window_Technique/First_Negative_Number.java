package array.Sliding_Window_Technique;

public class First_Negative_Number {

	public static void main(String[] args) {
		int arr[] = {1,3,-2,-7,1,3,-4}, k = 2;
		System.out.print("Array: ");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println("\nFirst Negative Number in every Window of Size K : \n");
		negative(arr,k);
		System.out.println("\nEff : ");
		eff(arr, k);
		
	}	
	static void eff(int arr[],int k) {
		for (int i = 0; i < k; i++) {
			if(arr[i]<0)System.out.print(arr[i]+" ");
		}
		for (int i = k; i < arr.length; i++) {
			if(arr[i-k+1]<0) System.out.print(arr[i-k+1]+" ");
			else	System.out.print(0+" ");
		}
		for (int i = arr.length-k; i < arr.length; i++) {
			if(arr[i]<0)System.out.print(arr[i]+" ");
		}
	}
	
	static void negative(int arr[],int k) {
		int sum=0;
		for (int i = 0; i < arr.length-k+1; i++) {
			for (int j = i; j < i+k; j++) {
				if(arr[j]<0) {
					System.out.print(arr[j]+" ");
					break;
				}
				else
					sum++;
			}
			if(sum>k-1) {
				System.out.print(0+" ");	sum=0;
			}
		}
	}

}
