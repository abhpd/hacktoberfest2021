class FindInMountain{

	public static int findInMountainArray(int target, int[] arr) {
		int peak = findPeak(arr);
		//ascending 
		int ans = orderAgnosticBinarySearch(arr,target,0,peak);
		return ans!=-1 ? ans : orderAgnosticBinarySearch(arr,target,peak+1,arr.length-1);


    }

    public static int orderAgnosticBinarySearch(int arr[],int target,int start,int end){
    	boolean isAscending = arr[start]<arr[end];

    	while(start<=end){
    		int mid = start+(end-start)/2;
    		if(arr[mid]==target){
    			return mid;
    		}
    		if(isAscending){
    			if(target>arr[mid]){
    				start = mid+1;
    			}else{
    				end = mid - 1;
    			}
    		}else{
    			if(target>arr[mid]){
    				end = mid - 1;
    			}else{
    				
    				start = mid+1;
    			}
    		}
    	}
    	return -1;
    }

    public static int findPeak(int arr[]){
    	int start = 0;
    	int end = arr.length-1;
    	while(start<end){
    		int mid = start+(end-start)/2;
    		if(arr[mid]>arr[mid+1]){
    			end = mid;
    		}else{
    			start = mid+1;
    		}
    	}
    	return start;
    }

	public static void main(String args[]){
		int[] arr = {1,2,3,4,5,4,3,2,1,0};
		System.out.println(findInMountainArray(0,arr));
	}
}