// Main merge sort function to sort arr
public static void mergeSort(int[] arr) {
		mergeSort(arr, 0, arr.length - 1);
	}

//helper function 1
// si - start index
// ei - end index
public static void mergeSort(int[] arr, int si, int ei) {
		if (ei - si == 0) {
			return;
		}

		int mid = (si + ei) / 2;
		mergeSort(arr, si, mid);
		mergeSort(arr, mid + 1, ei);
		merge(arr, si, mid, ei);
	}

// helper function 2
  private static void merge(int[] arr, int si, int mid, int ei) {
		if(si >= ei) {
			return;
		}
		
		int i = si, j = mid + 1;
		int k = 0;
		int[] temp = new int[ei - si + 1];
		
		while(i <= mid && j <= ei) {
			if(arr[i] <= arr[j]) {
				temp[k] = arr[i];
				k++;
				i++;
			} else {
				temp[k] = arr[j];
				k++;
				j++;				
			}
		}
		
		while(i <= mid) {
			temp[k] = arr[i];
			k++;
			i++;
		}
		
		while(j <= ei) {
			temp[k] = arr[j];
			k++;
			j++;
		}
		
		for(int t = 0; t < temp.length; t++) {
			arr[t + si] = temp[t];
		}			
		
	}
