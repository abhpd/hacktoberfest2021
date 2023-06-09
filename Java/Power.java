public class Power {
    public static void main(String[] args) {

        System.out.println(pow(2,2));
        System.out.println(pow(3,5));
    }

    public static double pow(int x, int n) {
        double ans = 1;
        while (n > 0) {
            if (n % 2 == 0) {
                x = x * x;
                n = n / 2;
            } else {
                ans = ans * x;
                n=n-1;
            }
        }
        return ans;
    }
}
