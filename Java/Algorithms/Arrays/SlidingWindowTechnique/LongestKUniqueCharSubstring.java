
/**
 * Author:  ARUN BALAJI R
 * Date:    10 August 2021 (Tuesday)
 */


import java.util.*;
public class LongestKUniqueCharSubstring{

	public static int longestKUniqueSubstring(String str,int k){
		int n = str.length();
		HashMap<Character,Integer> map = new HashMap<Character,Integer>();
		int windowStart = 0;
		int longestStringLen = -1;

		for(int windowEnd=0;windowEnd<n;windowEnd++){
			char c = str.charAt(windowEnd);
			map.put(c,map.getOrDefault(c,0)+1);


			//if unique size is 3 then computing windowlength

			if(map.size()==k){
				longestStringLen=Math.max(longestStringLen,(windowEnd-windowStart)+1);

			}
			//if unique size greater than k then move windowstart and remove element from map
			while(map.size()>k){
				Integer count = map.get(str.charAt(windowStart));
				if(count!=null && count > 1){
					map.put(str.charAt(windowStart),count-1);
				}else{
					map.remove(str.charAt(windowStart));
				}
				windowStart++;
			}

		}
		return longestStringLen;
		

	}


	public static void main(String args[]){
		
		System.out.println(longestKUniqueSubstring("aaaa",3));
	}
}