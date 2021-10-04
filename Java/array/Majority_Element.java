package array;

public class Majority_Element {

	public static void main(String[] args) {
		int arr[] = {1,2,3,3,3,6,3};
		System.out.println("Array : ");
		for (int i = 0; i < arr.length; i++) 
			System.out.print(arr[i]+" ");
		System.out.println("\nMajority Element : "+majority_Element(arr));
		System.out.println("Efficient method : "+eff_majority_Ekement(arr));
	}
	static int eff_majority_Ekement(int arr[]) {
		int res=0, count=1;
		for (int i = 1; i < arr.length; i++) {
			if(arr[res] == arr[i])
				count++;
			else	
				count--;
			if (count == 0) {
				res = i;
				count= 1;
			}
		}
		count = 0;
		for (int i = 0; i < arr.length; i++) 
			if(arr[res] == arr[i])
				count++;
		if(count <= arr.length/2)
			res=-1;
		
		return res;
	}
	
	static int majority_Element(int arr[]) {
		for (int i = 0; i < arr.length; i++) {
			int count = 1;
			for (int j = i+1; j < arr.length; j++) {
				if(arr[j] == arr[i]) count++;
			}
			if(count > arr.length/2)
				return i;
		}
		return -1;
	}
}
