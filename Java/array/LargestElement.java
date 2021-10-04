package array;

public final class LargestElement {

	public static void main(String[] args){
		int arr[] = {1,29,12,2,91}, i=0, n=arr.length;
		int lar = largest(arr),larInd = largestIndex(arr,i,n);
		int sec = secondLar(arr), SecInd = secLarIndex(arr,i,n);
		System.out.println("Largest element is: "+lar+" at "+larInd);
		System.out.println("Second largest is : "+sec+" at "+SecInd);
	}
	static int largest(int arr[]) {
		int n = arr.length, ele=arr[0];
		for(int i=0;i<n;i++) {
			if(arr[i]>ele)
				ele = arr[i];
		}
		return ele;
	}
	static int largestIndex(int arr[], int i, int n) {
		int index =0;
		for (i = 0; i < n; i++) {
			if(arr[i]>arr[index])
				index = i;
		}
		return index;
	}
	static int secondLar(int arr[]) {
		int lar=largest(arr),sec=arr[0], n=arr.length;
		for(int i=0;i<n;i++) {
			if(arr[i]>sec) {
				if(arr[i] == lar)
					continue;
				sec = arr[i];
			}
		}
		return sec;
	}
	static int secLarIndex(int arr[], int i, int n) {
		int Lin = largestIndex(arr,i ,n), Sin = 0;
		for ( i = 0; i < n; i++) {
			if(arr[i]>arr[Sin]) {
				if(arr[i] == arr[Lin])	continue;
				Sin = i;
			} 
		}
		return Sin;
	}
}
