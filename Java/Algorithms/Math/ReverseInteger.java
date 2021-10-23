public class ReverseInteger{
	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.reverse(-2147483648));		
	}
}


class Solution {
    public int reverse(int n) {
    	if(n==0)	return 0;
        int rem;
        long rev=0;
        boolean isNegative = n<0;
        if(isNegative) n = -1*n;
        while(n>0){
        	rem = n%10;
        	rev = rev*10+rem;
        	if(rev >= Integer.MAX_VALUE) return 0;
        	n/=10;	
        }
        return isNegative ? -1*(int)rev : (int)rev;
        

    }
}


/**
 * Author:
 * DateTime:    
 * Description: 
 */


import java.util.*;
public class ClassName{
	public static void main(String args[]){
		Solution s = new Solution();
		System.out.println();
	}
}
