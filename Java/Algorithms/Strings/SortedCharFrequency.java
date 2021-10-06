
/**
 * Author:  ARUN BALAJI R
 * Date:    23 August 2021 (Monday)
 */


import java.util.*;
public class SortedCharFrequency{

	public static void sortedCharFreq(String str){
		int[] count = new int[26];
		for(int i=0;i<str.length();i++){
			count[str.charAt(i)-'a']++;
		}

		for(int i=0;i<26;i++){
			if(count[i]>0)
				System.out.println((char)(i+'a')+" "+count[i]);
		}

	}


	public static void main(String args[]){
		
		sortedCharFreq("geeksforgeeks");
	}
}