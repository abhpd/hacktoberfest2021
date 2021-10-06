/**
 * Author:  ARUN BALAJI R
 * Date:    15 July 2021 (Thursday)
 */


import java.util.*;
public class FindTransitionPoint{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1};
		System.out.println(s.transitionPoint(arr,arr.length));
	}
}

class Solution{
	int transitionPoint(int arr[], int n) {
        int res = 0;
        for(int i=0;i<n;i++){
            if(arr[0]==1) return 0;
            if(arr[n-1]==0) return -1;
            if(arr[i]==1){
                res = i;
                break;
            }
        }
        return res;
    }
}
