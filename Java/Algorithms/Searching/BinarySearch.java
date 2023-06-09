import java.util.*;

public class BinarySearch {
    public static void main(String[] args) {
        int[] arr = {-2,0,3,5,7,9,12};
        int target = 3;
        int ans = binarySearch(arr, target);
        System.out.println(ans);
    }

    // return index
    // if not -1
    // This algo if for sorted in asc order
    // for dec if(target > mid) => end = mid -1
    // target < mid => start = mid + 1
    static int binarySearch(int[] arr, int target){
        int start = 0;
        int end = arr.length-1;

        while(start <= end){
            // start + end may give v.large value
            //int mid = (start+end)/2;

            //better approach
            int mid = start + (end-start)/2;

            if(arr[mid] == target){
                return mid;
            }
            else if(target < arr[mid]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        // if not found
        return -1;
    }

}
