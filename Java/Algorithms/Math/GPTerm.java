class GPTerm{
	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.termOfGP(1install));
	 	
	}
}

class Solution
{
    
    public double termOfGP(int A,int B,int N)
    {
        return (double)A*(double)Math.pow((B/A),N-1);
    }

}