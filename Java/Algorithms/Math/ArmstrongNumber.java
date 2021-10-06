
/**
 * Author:  ARUN BALAJI R
 * Date:    09 July 2021 (Friday)
 */


import java.util.*;
public class ArmstrongNumber{
	public static void main(String args[]){
		Solution s = new Solution();
		System.out.println(s.checkArmstrong(153));
	}
}

class Solution{
	public boolean checkArmstrong(int n){
		int temp = n;
		int sum = 0,rem;
		while(n>0){
			rem = n%10;
			n = n/10;
			sum+=rem*rem*rem;
		}
		return sum==temp;
	}
}