public class CheckPrime{
    public static void main(String args[]){
        Solution n = new Solution();
        System.out.println(n.checkPrime(45));
    }
}

class Solution{
    boolean checkPrime(int a){
        if(a==0 || a==1){
            return false;
        }
        else if(a==2)
            return true;
        else if(a%2==0 || a%5==0){
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

