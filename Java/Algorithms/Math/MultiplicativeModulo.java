class MultiplicativeModulo{
	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.modInverse(10,17));
	}

}


class Solution
{
    
	public int modInverse(int a, int m)
    {
 		for(int i=1;i<m;i++){
 			if((i*a)%m ==1)
 				return i;
 		}
 		return -1;
    }

}