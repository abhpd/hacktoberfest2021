class SearchInRotatedSortedArray{
	//solution : 1. convert rotated to normal (for that we need to find pivot)
			 //  2. to search  pivot+1 to end and start to pivot using binarysearcch
	//find pivot([3,4,0,1,2]) here 4 is pivot (transition point)
	public static int findPivot(int[] arr){
		int start = 0;
		int end = arr.length-1;
		while(start<=end){
			// 4 cases for finding pivot
			int mid = start+(end-start)/2;
			//case 1
			//because of mid+1 there might be a chance for overflow to avoid that we put mid<end
			if(mid<end && arr[mid] > arr[mid+1]){   
				return mid;
			}
			//case 2
			//for avoiding index errors mid should be greater than start
			if(mid>start && arr[mid] < arr[mid-1]){
				return mid-1;
			}
			//case 3:middle element should less than start because it is rotated
			if(arr[mid]<arr[start]){
				end = mid-1;
			}else{
				start = mid+1;
			}

		}
		return -1;
	}

	public static int findInRotated(int[] arr,int n,int target){
		int pivot = findPivot(arr);
		//if pivot is -1 this means array is not rotated
		if(pivot ==-1)
			return binarySearch(arr,0,n-1,target);
		if(arr[pivot]==target)
			return pivot;
		if(target >= arr[0]){
			return binarySearch(arr,0,pivot-1,target);
		}
		return binarySearch(arr,pivot+1,n-1,target);
		


	}

	public  static int binarySearch(int[] arr,int start,int end,int target){
		while(start<=end){
			int mid = start+(end-start)/2;
			if(target>arr[mid]){
				start = mid+1;
			}else if(target<arr[mid]){
				end = mid -1;
			}else{
				return mid;
			}
		}
		return -1;

	}

	public static void main(String args[]){
		int arr[] = {4,5,6,7,0,1,2};
		// System.out.println(findPivot(arr));
		int target = 2;
		System.out.println(findInRotated(arr,arr.length,target));
	}
}