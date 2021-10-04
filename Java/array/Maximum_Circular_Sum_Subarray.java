package array;
public class Maximum_Circular_Sum_Subarray {

	public static void main(String[] args) {
		int arr[] = {3, -4, 5, 6, -8, 7};
		System.out.println("Array :");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println("\nMaximum Cirular Sum SubArray :");
		System.out.println("naive method 1 : "+naive_Max_Circular_SubArray_Sum(arr));
		System.out.println("naive method 2 : "+naive2_Max_Circular_SubArray_Sum(arr));
		System.out.println("Efficient Method : "+eff_Max_Circular_SubArray_Sum(arr));
	}
	// Efficient method using wrapper property which is
	// Max SubArray Sum =  Sum of Normal Array - Min SubArray Sum
	static int eff_Max_Circular_SubArray_Sum(int arr[]) {
		int max_sum=0;
		int sum = 0;
		for (int i = 0; i < arr.length; i++) { 
			sum += arr[i];
			arr[i] = -arr[i];		
		}
		int min_sum = -Max_SubArray_Sum.eff_maxSum(arr);
		max_sum = sum - min_sum; 
		return max_sum;
	}
	
	// in this naive method 1,to find max SubArray sum(All the array element as starting element
	// of new array, by rotation) array rotation
	static int naive_Max_Circular_SubArray_Sum(int arr[]) {
		int max= Max_SubArray_Sum.eff_maxSum(arr); // Kadense Algo mrthod for max  subarray sum
		for (int i = 1; i < arr.length; i++) {
			Left_Rotation.LR(arr); // calling LR method from Left_Rotation class
			max = Math.max(max, Max_SubArray_Sum.eff_maxSum(arr));
		}
		return max;
	}
	// no array rotation, using modulus operator instead
	static int naive2_Max_Circular_SubArray_Sum(int arr[]) {
		int res = arr[0]; 
		for (int i = 0; i < arr.length; i++) {
			int curr_max = arr[i];
			int sum = arr[i];
			for (int j = 1; j < arr.length; j++) {
				int index = (i+j)%arr.length;
				sum += arr[index];
				curr_max = Math.max(sum, curr_max);
			}
			res = Math.max(res, curr_max);
		}
		return res;
	}
}
