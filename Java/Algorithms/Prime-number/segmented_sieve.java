import java.util.*;

public class Main {

  // ~~~~~~~~~~~~~User Section~~~~~~~~~~~~

  public static void segmentedSieveAlgo(int a, int b) {
      int n = (int)Math.sqrt(b);
    ArrayList<Integer> primes = Sieve(n);
    boolean[] ans = new boolean[b-a+1];
    
    for(int prime : primes )
    {
        int number = (int)Math.ceil(a/(prime*1.0));
        int start = number * prime - a ;
        for(int j = start ; j < ans.length ; j+=prime)
        {
            if(ans[j] == false)
                ans[j] = true ;
        }
    }
    for(int i = 0 ; i < ans.length ; i++)
    {
        int val = i + a ;
        if(ans[i] == false && val > 1 )
        {
            System.out.println(val);
        }
    }
  }
  public static ArrayList Sieve(int n)
  {
     boolean[] primes = new boolean[n+1];
     ArrayList<Integer> p = new ArrayList<>();
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
                p.add(i);
            
        }
        return p ;
  }

  // ~~~~~~~~~~~~Input Management~~~~~~~~~~~
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int a = scn.nextInt();
    int b = scn.nextInt();
    segmentedSieveAlgo(a, b);
  }
}
