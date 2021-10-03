import java.lang.*;
import java.util.*;

public class LinearSearch{

    public static void main(String[] args) {
	    /*
        Time complexity :
            Best Case - O(1)
            Worst Case - O(n)
	     */

        int[] nums = {1,4,2,5,34,74};
        int target = 2;
        System.out.println(linearSearch(nums,target));
    }

    // search in array
    // return index if found else return -1 if not found
    static int linearSearch(int[] arr, int target){
        if(arr.length == 0){
            return -1;
        }

        for (int i = 0; i < arr.length; i++) {
            if(arr[i] == target){
                return i;
            }
        }

        return -1;
    }

}
