package array;

public class Max_Consecutive_1 {

	public static void main(String[] args) {
		int arr[] = {1,1,1,6,1,1,1,1,1,4,9};
		System.out.println("Array : ");
		for (int i = 0; i < arr.length; i++) 
			System.out.print(arr[i]+" ");
		int res = Max_1(arr);
		System.out.println("\nMaximum Consecutive number of 1 : "+res);
		}
	static int Max_1(int arr[]){
		int max=0, time =0;
		for (int i = 0; i < arr.length; i++) {
			if(arr[i] == 1) 
				time++;
			else {
				if(max < time) {
					max = time;
				}
				time =0;
			}
			
		}
		return max;
	}
	
	
}
