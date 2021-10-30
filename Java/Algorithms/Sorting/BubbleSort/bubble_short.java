package structure_JAVA;

import java.util.Arrays;

public class bubble_short {

	public static void main (String[] args) {

		int [] arr = {2,4,8,1,23};
		bubble(arr);
		System.out.println(Arrays.toString(arr));





	}
	static void  bubble(int [] arr) {
		// run the steps for n-1 times.
		boolean swapped;

   for(int i = 0 ; i<arr.length;i++) {
			swapped = false;
			for(int j = 1 ; j<arr.length-1;j++) {

				if(arr[j]<arr[j-1]) {

					
					int temp = arr[j];
					arr[j] = arr[j-1];
					arr[j-1] = temp;
					swapped = true; 

				}
			}

			
			// if u did not swap for particular value of the i it means stop the program from swappping
			
			if(!swapped) {
				
				break;
			}
			
		}


	}

}
