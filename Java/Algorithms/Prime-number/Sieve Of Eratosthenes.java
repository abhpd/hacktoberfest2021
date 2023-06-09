import java.util.*;

public class Main {
    
    // ~~~~~~~~~~~~~~~~~~User Section~~~~~~~~~~~~~~~~
    public static void printPrimeUsingSieve(int n) {
        boolean[] primes = new boolean[n+1];
        Arrays.fill(primes,true);
        for(int i = 2 ; i*i <= n ; i++)
        {
            if(primes[i] == true)
            {
                for(int j = i+i ; j <= n ; j+=i)
                {
                    primes[j] = false ;
                }
            }
        }
        for(int i = 2 ; i <= n ; i++ )
        {
            if(primes[i] == true)
            System.out.print(i + " ");
        }
    }
    

    // ~~~~~~~~~~~~~~~~Input Management~~~~~~~~~~~~~~
    public static void main(String[] args) {   
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        printPrimeUsingSieve(n);
    }
}
