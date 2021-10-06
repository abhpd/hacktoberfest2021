public class Lab1 {
    public static void main(String[] args) {
        for (int i = 5; i > -5; i--) {
            for (int j = 0; j < i; j++) {
                System.out.print(" ");
            }
            for (int j = 0; j >= i; j--) {
                System.out.print(" ");
            }
            System.out.println("*");
        }
    }
}
