public class PrintNPrime{
    public static void main(String[] args) {
        printPrime(10);
        
    }

    static void printPrime(int n){
        for(int i=0;i<n;i++){
            if(checkPrime(i))
                System.out.println(i);
        }
        
    }
    
    static boolean checkPrime(int a){
        if(a==0 || a==1){
            return false;
        }
        else if(a==2)
            return true;
        else if(a%2==0){
            return false;
        }
        else{
            for(int i=3;i<=Math.sqrt(a);i+=2){
                if(i%2==0){
                    return false;
                }
            }
        }
        return true;
    }
}

