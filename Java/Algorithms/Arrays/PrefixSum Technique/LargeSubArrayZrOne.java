
/**
 * Author:  ARUN BALAJI R
 * Date:    11 August 2021 (Wednesday)
 */


import java.util.*;
public class LargeSubArrayZrOne{

	public static int maxLen(int[] arr, int n)
    {
        //step 1 : make all zeros to -1
        for(int i=0;i<n;i++){
            if(arr[i]==0) arr[i]=-1;
        }

        //step 2 : prefix sum
        int maxLen = 0,prefixSum = 0;
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i=0;i<n;i++){
        	prefixSum+=arr[i];
        	if(prefixSum==0)	maxLen=i+1;
        	if(map.containsKey(prefixSum)){
        		maxLen = Math.max(maxLen,i-map.get(prefixSum));
        	}else{
        		map.put(prefixSum,i);
        	}

        }
    	return maxLen;    
    }


	public static void main(String args[]){
		int[] arr = {0,1,0,1};
		System.out.println(maxLen(arr,arr.length));
	}
}