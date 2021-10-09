class RunLengthEncoding{

	public static String encode(String str){
		int count = 1;
		String res = "";

		for(int i=0;i<str.length();i++){
			if(i<str.length()-1 && str.charAt(i)==str.charAt(i+1))
				count++;
			else{
				res+=""+str.charAt(i)+count;
				count = 1;
				
			}
		}

		return res;
	}

	public static void main(String args[]){
		String str = "aaaabbbccc";
		//expected output : a4b3c3
		System.out.println(encode(str));
	}
}