/**
 * Author:  Soumen Roy
 * Date:    10 October 2021 (Friday)
 */

public class ReverseOnlyVowels {

	//driver method - main
	public static void main(String[] args) {
		String s = "Hello, reverse mo"; //hardcoded string, serves as input
		String str = reverseVowels(s);
		System.out.println(str); // output - Holle, reverso me
	}

	//isVowel method checks whether a character is vowel or not
	public static boolean isVowel(char c) {
		return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O'
				|| c == 'U');
	}

	//reverseVowels method reverses/swaps only the vowels from the input string
	public static String reverseVowels(String str) {
		//return if it is a single character, edge case
		if (str.length() < 2) {
			return str;
		}
		//Two-pointer method
		int start = 0;  
		int end = str.length() - 1;
		char[] c = str.toCharArray();
		while (start < end) {
			if (!isVowel(c[start])) {
				start++;
			}
			if (!isVowel(c[end])) {
				end--;
			}
			if (isVowel(c[start]) && isVowel(c[end])) {
				str = swap(str, start, end);
				start++;
				end--;
			}
		}
		return str;
	}

	//swap method swaps the characters which are vowels
	static String swap(String s, int start, int end) {
		char[] c = s.toCharArray();
		int temp = c[start];
		c[start] = c[end];
		c[end] = (char) temp;
		return String.valueOf(c);
	}

}
