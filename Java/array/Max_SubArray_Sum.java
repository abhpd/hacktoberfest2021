package array;

public class Max_SubArray_Sum {
	// kadense algorithm
	static int eff_maxSum(int arr[]) {
		int res=arr[0],max=arr[0];
		for (int i = 1; i < arr.length; i++) {
			max += arr[i];
			max = Math.max(max, arr[i]);
			// instead of above two line you can use below single line code
			//max =Math.max(max + arr[i], arr[i]);
			res = Math.max(max, res);
		}
		return res;
	}

	public static void main(String[] args) {
		int arr[] = {-5, 1, -2, 3, -1, 2, -2};
		System.out.println("Array :");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println("\nMax Sum of SubArray is : "+eff_maxSum(arr));
	}
	static int maxSum(int arr[]) {
		int max=0;
		for (int i = 0; i < arr.length; i++) {
			int sum=0;
			for(int j=i;j<arr.length;j++) {
				sum += arr[j];
				max = Math.max(max, sum);
			}
		}
		return max;
	}


}
