import java.util.*;

class NoOfDigInFact{
	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.digitsInFactorial(5));
	}	
}

class Solution{
	
    public int digitsInFactorial(int N){
    	double logsum = 0;
    	if(N==0)
    		return 0;
    	else if(N==1)
    		return 1;
    	else{
    		for(int i=2;i<=N;i++){
    			logsum+=Math.log10(i);
    	}
    	return (int)logsum+1;


    }


    
}