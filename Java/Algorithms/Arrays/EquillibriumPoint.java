
/**
 * Author:  ARUN BALAJI R
 * Date:    16 July 2021 (Friday)
 */


import java.util.*;
public class EquillibriumPoint{
	public static void main(String args[]){
		Solution s = new Solution();
		long arr[] = {20,17,42,25,32,32,30,32,37,9,2,33,31,17,14,40,9,12,36,21,8,33,6,6,10,37,12,26,21,3};
		System.out.println(s.equilibriumPoint(arr,arr.length));
		System.out.println(arr.length);
	}
}


class Solution {

    
    // a: input array
    // n: size of array
    // Function to find equilibrium point in the array.
    public static int equilibriumPoint(long arr[], int n) {
        long sum = 0,leftsum = arr[0];
        for(int i=0;i<n;i++)    sum+=arr[i];
        for(int i=1;i<n;i++){
            if(leftsum==(sum-leftsum-arr[i]))   return i;
            leftsum+=arr[i];
        }
        return (n!=1) ? -1 : 1;
    }    
}
