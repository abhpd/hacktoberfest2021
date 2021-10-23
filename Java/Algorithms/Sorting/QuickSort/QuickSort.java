
public class QuickSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int a[] = {2,3,8,10,11,6,9,5};
		sort(a, 0, a.length - 1);
		for (int val : a) {
			System.out.println(val + " ");
		}

	}
	static void display(int a[])
	{
		for(int i=0;i<a.length;i++)
			System.out.print(a[i]+" ");
		System.out.println();
	}

	public static void sort(int a[], int lo, int hi) {

		if (lo >= hi) // if only one element left or lo>ho
			return;
		// partioning
		int m = (lo + hi) / 2;
		int pivot = a[m];
		int l = lo;
		int r = hi;
		while (l <= r) // till it do not cross each other
		{
			//increment l until u find an element greater than pivot
			while (a[l] < pivot) {
				l++;
			}
			//decrement r until u find an elemnt smaller than pivot
			while (a[r] > pivot) {
				r--;
			}
//and then swap them
			if (l <= r) { // to stop swapping if l and r has already swapped
				int temp = a[l];
				a[l] = a[r];
				a[r] = temp;
				l++;
				r--;
			}
			System.out.println(pivot);
			display(a);
		}
	

		sort(a, lo, r);
		sort(a, l, hi);

	}

}
