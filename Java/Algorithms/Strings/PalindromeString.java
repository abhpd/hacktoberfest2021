class PalindromeString{

	public static void main(String args[]){
		System.out.println(checkPalindrome("a"));
	}

	public static boolean checkPalindrome(String str){
		int a,l;
	    char ch;
	    String str1,nstr="";
	    str1=str.toLowerCase();
	    l=str1.length();
	    for (a=(l-1); a>=0; a--)
	    {
	        ch=str1.charAt(a);
	        nstr=nstr+ch;
	    }
	    if(nstr.equals(str1))
	    {
	        return true;
	    }
	    else
	    {
	        return false;
	    }
	}
}