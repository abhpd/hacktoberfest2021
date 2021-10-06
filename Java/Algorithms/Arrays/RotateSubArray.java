
/**
 * Author:  ARUN BALAJI R
 * Date:    14 July 2021 (Wednesday)
 */


import java.util.*;
public class RotateSubArray{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[]= {1,2,3,4,5};
		s.rotateSubArray(arr,3);
	}
}

class Solution{
	public void rotateSubArray(int arr[],int k){
		ro
		for(int i:arr){
			System.out.print(i+" ");
		}
	}

	for(int i=0;i<n;i=i+k){
            int left=i;
            int right=Math.min(i+k-1,n-1);
            int temp;

            while(left<right){
                temp=arr.get(left);
                arr.set(left, arr.get(right));
                arr.set(right,temp);
                left=left+1;
                right=right-1;
            }
        }

}