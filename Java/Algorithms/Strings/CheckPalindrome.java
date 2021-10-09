
/**
 * Author:  ARUN BALAJI R
 * Date:    27 August 2021 (Friday)
 */


import java.util.*;
public class CheckPalindrome{
	public static void main(String args[]){
		String s = "racecar";
		System.out.println(checkPalindromeNaive(s));
	}

	// using string builder
	public static boolean checkPalindromeNaive(String str){
		StringBuilder s = new StringBuilder(str.toLowerCase());
		s.reverse();
		return str.equals(s.toString());
	}

	public  static boolean checkPalindrome(String str){
		char[] arr = str.toLowerCase().toCharArray();
		int start = 0;
		int end = arr.length-1;

		while(start<end){
			if(arr[start]!=arr[end]){
				return false;
			}
			start++;
			end--;
		}

		return true;
	}
}