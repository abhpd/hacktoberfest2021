
/**
 * Author:  ARUN BALAJI R
 * Date:    25 August 2021 (Wednesday)
 */


import java.util.*;
public class IndexOfExtra{
	public static void main(String args[]){
		int[] A = {3,5,7,9,11,13};
		int [] B = {3,5,7,11,13};
		System.out.println(findExtra(A,B,A.length));
	}

	public static int findExtra(int a[], int b[], int n) {
        int start = 0;
        int end = n-1;
        int res = 0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(a[mid]!=b[mid]){
            	res = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return res;
        
    }
}