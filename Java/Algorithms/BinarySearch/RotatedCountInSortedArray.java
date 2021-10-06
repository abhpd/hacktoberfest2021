class RotatedCoundInSortedArray{

	//it is nothing but pivot + one
	public static int findPivot(int arr[], int n) {
        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(mid < end && arr[mid] > arr[mid+1])
                return mid+1;
            if(mid > start && arr[mid] < arr[mid-1])
                return mid;
            if(arr[start]>arr[mid])
                end = mid-1;
            else
                start = mid+1;
        }
        return 0;
    }

	public static void main(String args[]){
		int arr[] = {5,1,2,3,4};
		System.out.println(findPivot(arr,arr.length));
	}
}	