
/**
 * Author:  ARUN BALAJI R
 * Date:    15 July 2021 (Thursday)
 */


import java.util.*;
public class WhoHasMajaroity{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {5,22,29,12,32,69,1,75};
		System.out.println(s.getMajority(arr,arr.length,29,96));
	}
}

class Solution {
    // Function to find element with more appearances between two elements in an
   // array.
    public int majorityWins(int arr[], int n, int x, int y) {
        int xcount = 0;
        int ycount = 0;
        for(int i=1;i<n;i++){
            if((arr[i] == x) || arr[i]==arr[i-1]){
                xcount++;
            }
            if(arr[i]== y || arr[i]==arr[i-1]){
                ycount++;
            }
        }
        
        System.out.println(xcount+" "+ycount);
        if(xcount>ycount)
        	return x;
        else if(ycount > xcount)
        	return y;
        else
        	return Math.min(x,y);
    }

    int getMajority(int arr[],int n,int x,int y){
    	int xcount = 0;
    	int ycount = 0;
    	for(int i=0;i<n;i++){
    		if(arr[i]==x)	xcount++;
    		if(arr[i]==y) 	ycount++;
    	}
    	System.out.println(xcount+"  "+ycount);
    	return (xcount==ycount) ? Math.min(x,y) : ((xcount>ycount) ? xcount : ycount);
    }

}