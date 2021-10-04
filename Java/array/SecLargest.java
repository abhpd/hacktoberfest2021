package array;

public class SecLargest {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[] = {8,4,6,9,1,5,9};
		int res = largest(arr);
		System.out.println("Largest element is "+res);
		int res2 = secondLargest(arr);
		System.out.println("Second Largest element is "+res2);
	}
	static int largest(int arr[]) {
		int ele = 0,i;
		for(i=0;i<arr.length;i++) {
			if(arr[i] >ele)
				ele = arr[i];
		}
		return ele;
	}
	static int secondLargest(int arr[]) {
		int n = arr.length, second = Integer.MIN_VALUE;
		int first = arr[0];
		for(int i = 1; i<n; i++) {
			if(arr[i] > first) {
				second = first;
				first = arr[i];
			}
			else if (arr[i] > second && arr[i] != first)
				second = arr[i];
				
		}
		return second;
	}
}
