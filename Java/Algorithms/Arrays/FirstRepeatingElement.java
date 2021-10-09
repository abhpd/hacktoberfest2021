
/**
 * Author:  ARUN BALAJI R
 * Date:    21 July 2021 (Wednesday)
 */


import java.util.*;
public class FirstRepeatingElement{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[]={1, 5, 3, 4, 3, 5, 6};
		System.out.println(s.getFirstRepeat(arr,arr.length));
	}
}

class Solution{
	int getFirstRepeat(int arr[],int n){
		Set<Integer> set = new HashSet<>();
		int repeat = -1;
		for(int i=n-1;i>=0;i--){
			if(set.contains(arr[i])){
				repeat=i;
			}else{
				set.add(arr[i]);
			}
		}
		return repeat ==-1 ? -1 : repeat+1;
	}
}