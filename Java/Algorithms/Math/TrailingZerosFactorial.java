public class TrailingZerosFactorial{
    public static void main(String[] args) {
        System.out.println(trailingZeros(5));
    }

    static int trailingZeros(int n){
        int ans = 0;
        int pow = 5;
        while(n/pow>0){
            ans += n/pow;
            pow = pow*5;
        }
        return ans;
    }
}