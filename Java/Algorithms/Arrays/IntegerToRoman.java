
/**
 * Author:  ARUN BALAJI R
 * Date:    28 June 2021 (Monday)
 */


import java.util.*;
public class IntegerToRoman{
	public static void main(String args[]){
		Solution s = new Solution();
		System.out.println(s.intToRoman(1994));
	}
}


class Solution {
    public String intToRoman(int num) {
    	
    	String units[] =   {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    	String tens[] =    {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    	String hunderds[] ={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    	String thousands[]={"","M","MM","MMM"};
    	return thousands[num/1000] +
    		   hunderds[(num%1000)/100]+
    		   tens[(num%100)/10] +
    		   units[num%10];
    
    }
}