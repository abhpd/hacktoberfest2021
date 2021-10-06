
/**
 * Author:  ARUN BALAJI R
 * Date:   27 August 2021 (Friday)
 */


import java.util.*;
public class Anagram{
	public static void main(String args[]){
		
		System.out.println(checkAnagram("arun","nura"));
	}


	//anagram means all letters in another word
	public static boolean checkNaiveAnagram(String str1,String str2){
		if(str1.length()!=str2.length()){
			return false;
		}
		char[] s1 = str1.toCharArray();
		Arrays.sort(s1);
		System.out.println(s1);
		str1 = new String(s1);
		char[] s2 = str2.toCharArray();
		Arrays.sort(s2);
		System.out.println(s2);
		str2 = new String(s2);

		return str1.equals(str2);


	}

	static final int CHAR = 256; //char has 256 byter
	public  static boolean checkAnagram(String str1,String str2){
		if(str1.length()!=str2.length()){
			return false;
		}
		int[] count= new int[CHAR];
		for(int i=0;i<str1.length();i++){
			count[str1.charAt(i)]++;
			count[str2.charAt(i)]--;
		}

		for(int i=0;i<count.length;i++){
			if(count[i]!=0){
				return false;
			}
		}
		return true;

	}
}