import java.util.*;

class LeftMostNonRepeatingChar{
	static final int CHAR = 256;

	public static void main(String args[]){
		String str = "geeksforgeeks";
		//expected output :5(f's index)
		System.out.println(indexOfLeftmostNonrepeat(str));
	}

	public static int indexOfLeftmostNonrepeat(String s){
		 
		int[] count = new int[CHAR];
		for(int i=0;i<s.length();i++){
			count[s.charAt(i)]++;
		}

		for(int i=0;i<s.length();i++){
			if(count[s.charAt(i)]==1)
				return i;
			
		}
		return -1;
	}




}