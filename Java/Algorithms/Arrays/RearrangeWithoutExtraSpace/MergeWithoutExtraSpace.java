
/**
 * Author:  ARUN BALAJI R
 * Date:    12 August 2021 (Thursday)
 */


import java.util.*;
public class MergeWithoutExtraSpace{
	public static void main(String args[]){
		Solution s = new Solution();
		long arr1[] = {1,3,5,7};
		long arr2[] = {0,2,6,8,9};
		s.merge(arr1,arr2,arr1.length,arr2.length);
	}
}

class Solution
{
    //Function to merge the arrays.
    public static void merge(long arr1[], long arr2[], int n, int m) 
    {
        for(int i=0;i<n;i++){
            if(arr1[i]>arr2[0]){
                //swaping
                arr1[i]=arr1[i]+arr2[0];
                arr2[0]=arr1[i]-arr2[0];
                arr1[i]=arr1[i]-arr2[0];
                // System.out.println(Arrays.toString(arr2));
                
                Arrays.sort(arr2);
                
                
            }
        }
        System.out.println(Arrays.toString(arr1)); 
        System.out.println(Arrays.toString(arr2));
    }
    
    


}