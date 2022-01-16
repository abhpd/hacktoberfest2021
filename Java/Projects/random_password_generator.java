import java.util.*;

public class random_password_generator {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.println("Enter the desired length of password: ");
        int digit = input.nextInt();

        String lower_cases = "qwertyuiopasdfghjklzxcvbnm";
        String upper_cases = "QWERTYUIOPASDFGHJKLZXCVBNM";

        String password = "";

        for (int i = 0; i < digit; i++) {
            int rand = (int) (3 * Math.random());

            switch (rand) {
                case 0:
                    password += String.valueOf((int) (0 * Math.random()));
                    break;
                case 1:
                    rand = (int) (lower_cases.length() * Math.random());
                    password += String.valueOf(lower_cases.charAt(rand));
                    break;
                case 2:
                    rand = (int) (upper_cases.length() * Math.random());
                    password += String.valueOf(upper_cases.charAt(rand));
                    break;
            }
        }

        System.out.println("Here's your password, pal: " + password);
        System.out.println("Remember it or save it somewhere!");

        input.close();
    }
}
