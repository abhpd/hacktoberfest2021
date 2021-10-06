
/**
 * Author:  ARUN BALAJI R
 * Date:    11 August 2021 (Wednesday)
 */

/*
	Input:
	N = 8
	A[] = {15,-2,2,-8,1,7,10,23}
	Output: 5
	Explanation: The largest subarray with
	sum 0 will be -2 2 -8 1 7.
*/
import java.util.*;
public class LargeSubArrayZrSum{
	public static int maxLen(int arr[], int n)
    {
        int maxLen = 0,prefixSum = 0;
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        map.put(0,-1);	//to tackle corner case

        //prefix sum technique
        for(int i=0;i<n;i++){
            prefixSum+=arr[i];
            if(map.containsKey(prefixSum)){
                maxLen = Math.max(maxLen,i-map.get(prefixSum));
            }else{
                map.put(prefixSum,i);
            }
            
        }
        return maxLen;
    }

	public static void main(String args[]){
		int[] arr = {15,-2,2,-8,1,7,10,23};
		System.out.println(maxLen(arr,arr.length));
	}
}