public class ValPerfSquare{
    public static void main(String args[]){
        Solution n = new Solution();
        System.out.println(n.checkPrime(45));
    }
}

class Solution {
    public boolean isPerfectSquare(int num) {
        long high = (long) num+1;
        long low = -1;
        while(low!=high-1){
            long mid = (low+high)/2;
            if(mid*mid==num) return true;
            else if(mid*mid>num) high = mid;
            else low = mid;
        }
        return false;
    }
}