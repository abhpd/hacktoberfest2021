
/**
 * Author:  ARUN BALAJI R
 * Date:    19 July 2021 (Monday)
 */


import java.util.*;
public class WaveArray{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {2,4,7,8,9,10};
		s.convertToWave(arr,arr.length);
		s.printArray(arr);
	}
}

class Solution{  
    // arr: input array
    // n: size of the array
    //Function to sort the array into a wave-like array.
    public static void convertToWave(int arr[], int n){
        
        for(int i=1;i<n;i+=2){
           	arr[i-1] = arr[i-1] + arr[i];
        	arr[i] = arr[i-1] - arr[i];
        	arr[i-1] = arr[i-1] - arr[i];
        
        }
        
    }
    
    

    public static void printArray(int arr[]){
    	for(int i:arr){
    		System.out.print(i+" ");
    	}
    }
    
    
}