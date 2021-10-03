
import java.lang.*;
import java.util.*;

/*
In general we didnt know wheter the 
sorted array is in ascending or descending.
So order Agnostic Binary Search identifies
first the nature of sorted array and then 
search using algorithm

*/

public class OrderAgnosticBS {
    public static void main(String[] args) {
        int[] arr1 = {-2,0,3,5,7,9,12};
        int target = 3;
        int ans = orderAgnosticBS(arr1, target);
        System.out.println("In asc order " +target + " is at index : " + ans);

        int[] arr2 = {13,11,5,4,3,2,1};
        System.out.println("In Desc order " + target + " is at index : " + orderAgnosticBS(arr2,target));
    }
	
	
    static int orderAgnosticBS(int[] arr, int target){
        int start = 0;
        int end = arr.length-1;

        // find whether array sorted in asc or desc
        boolean isAsc = arr[start] < arr[end];

        while(start <= end){
            // start + end may give v.large value
            //int mid = (start+end)/2;

            //better approach
            int mid = start + (end-start)/2;
            if (arr[mid] == target) {
                return mid;
            }

            if(isAsc) {
                if (target < arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            else{
                if (target < arr[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
}
