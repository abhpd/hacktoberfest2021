import java.util.Arrays;
public class Recursivebubblesort {
	public static void main(String[] args) {
		int[] nums = {5, 4, 8, 9, 1, 2, 7, 6};
		sort(nums, nums.length);
		System.out.print(Arrays.toString(nums));
	}
	static void sort(int[] arr, int n) {
		if (n == 1) return;
		for (int i = 0; i < n - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
			}
		}
		sort(arr, n - 1);
	}
}