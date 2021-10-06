import java.util.*;

public class SieveOfEratosthenes {
    public static void main(String[] args) {
        printNPrime(10);
    }   
    
    static void printNPrime(int n){


        // fill the boolean array of size n with true values
        Boolean arr[] = new Boolean[n+1];
        Arrays.fill(arr, Boolean.TRUE);
        //only n/2 occurs prime here after no non prime nos occur so
        for(int p=2;p*p<=n;p++){
            if(arr[p] == true){
                //make all multiples false
                for(int i=2;i*i<=n;i+=p){
                    arr[i]=false;
                }
            }
        }

        for(int i=2;i<=n;i++){
            if(arr[i]==true)
                System.out.print(i+" ");
        }
    }

}
