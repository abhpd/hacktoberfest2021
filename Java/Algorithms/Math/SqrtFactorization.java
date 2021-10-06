import java.util.*;



public class SqrtFactorization {

    public static ArrayList<Long> factorize(long number) {
        ArrayList<Long> factors = new ArrayList<Long>();
        for (Long i = 1l; (i*i) <= number; i++) {
            if ((number%i) == 0) {
                if ((number/i) != i) {factors.add(number/i);}
                factors.add(i);
            }
        }
        return factors;
    }

    public static void main(String[] args) {
        // Test: should be [1, 2, 5, 10]
        System.out.println(factorize(10));
    }
}
