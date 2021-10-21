/**
 * Author:  AKSHAY WAKHARE
 * Date:    22 October 2021
 */


import java.util.*;
public class JumpGame{

	public static void main(String args[]){
		JumpGame s = new JumpGame();
		int arr[] = {2,4,6,3,4,6};
		
		if(s.isPosssible(arr)){
		System.out.println(s.minJumps(arr));}
		else{
		System.out.println("Not Possible");
		}
	}


    public boolean isPosssible(int[] nums) {
        
        int n = nums.length;
        
        //last index from where we can reach to end cell
        //As from last index (n - 1) itself reach to  end cell,  
        int lastIndex = n - 1;
        
        for(int i = n - 1; i >= 0; i--){
            if(i + nums[i] >= lastIndex){
                lastIndex = i;
            }
        }
        
        //check from 0 reach to end cell
        return lastIndex == 0;
    }



public int minJumps(int[] A) {
	int jumps = 0, curEnd = 0, curFarthest = 0;
	for (int i = 0; i < A.length - 1; i++) {
		curFarthest = Math.max(curFarthest, i + A[i]);
		if (i == curEnd) {
			jumps++;
			curEnd = curFarthest;
		}
	}
	return jumps;
}