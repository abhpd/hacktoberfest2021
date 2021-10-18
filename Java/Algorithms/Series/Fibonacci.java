public class Fibonacci {
    public static void main(String[] args) {
        int n = 10; //number count in series
        int previousValue = 0;
        int nextValue = 1;

        System.out.print("Fibonacci series of " + n + " numbers: ");

        for (int i = 1; i <= n; i++) {
            System.out.print(previousValue + " ");

            int sum = previousValue + nextValue;
            //Each iteration, assign nextValue to the previousValue
            previousValue = nextValue;
            //assign sum of last two values to the next value in the series
            nextValue = sum;
        }
    }
}
