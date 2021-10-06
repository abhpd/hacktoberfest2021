import java.util.*;

class AdditionUnderModulo{
	public static void main(String[] args) {
		
		System.out.println(sumUnderModulo(9223372036854775807l,9223372036854775807l));

	}

	public static long sumUnderModulo(long a, long b){
		long d = (long)Math.pow(10,9)+7;
        a = (long)a%d;
        b = (long)b%d;
        return (a+b)%d;
    }  
}