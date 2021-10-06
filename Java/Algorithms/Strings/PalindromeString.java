class PalindromeString{

	public static void main(String args[]){
		System.out.println(checkPalindrome("a"));
	}

	public static boolean checkPalindrome(String str){
		int n = str.length();
		if(n==0 || n==null)
			return true;
		for(int i=0;i<n/2;i++){
			if(str.charAt(i)!=str.charAt(n-1-i))
				return false;
		}
		return true;
	}
}