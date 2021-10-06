class LeftMostRepeatingChar{

	public static void main(String args[]){
		String str = "geeksforgeeks";
		System.out.println(indexOfLeftmostrepeat(str));
	}

	public static int indexOfLeftmostrepeat(String str){
		int n = str.length();
		char c = str.charAt(0);
		for(int i=1;i<n;i++){
			if(c==str.charAt(i)){
				return i-1;
			}else{
				c = str.charAt(i);
			}

		}
		return -1;
	}
}