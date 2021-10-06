
/**
 * Author:  ARUN BALAJI R
 * Date:    21 July 2021 (Wednesday)
 */


import java.util.*;
public class ImmediateSmallerThanX{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {4,67,13,12,15};
		System.out.println(s.immediateSmaller(arr,arr.length,16));
	}
}


class Solution
{
    // Complete the function
    public static int immediateSmaller(int arr[], int n, int x)
    {   
        int min = -1;
        for(int i=0;i<n;i++){
            if(arr[i]<x){
                min = Math.max(arr[i],min);
            }
        }
        return min == -1 ? -1 : min;
    }
}