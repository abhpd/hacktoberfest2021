import java.util.*;

public class ExactlyThreeDivisors{
	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.exactly3Divisors(10));
	}
}

class Solution
{	

	public int exactly3Divisors(int N)
    {	
    	boolean arr[] = new boolean[999999+1];
    	for(int i=0;i<=999999;i++){
    		arr[i]=true;
    	}
    	for(int i=2;i*i<=999999;i++){
    		if(arr[i]){
    			for(int j=i*i;j<=999999;j+=i){
    				arr[j]=false;
    			}
    		}
    	}

    	int c=0;
    	if(N==1||N==2)
    		return 0;
        for(int j=2;j*j<=N;j++){
        	if(arr[j])
        		c++;        
        }
        return c;
    }
}