public class CheckPrime{
    public static void main(String args[]){
        Solution n = new Solution();
        System.out.println(n.checkPrime(45));
    }
}

class Solution{
    boolean checkPrime(int num){
    boolean flag = false;
    for (int i = 2; i <= num / 2; ++i) {
      // condition for nonprime number
      if (num % i == 0) {
        flag = true;
        break;
      }
    }
return flag;
}

