import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double number1, number2, result;
        char operator;

        System.out.print("Input the first number : ");
        number1 = input.nextDouble();
        System.out.print("Input the operator (+, _, *, /)");
        operator = input.next().charAt(0);
        System.out.print("Input the second number : ");
        number2 = input.nextDouble();


        switch (operator) {
            case '+' -> {
                result = number1 + number2;
                System.out.println(number1 + " + " + number2 + " = " + result);
            }
            case '-' -> {
                result = number1 - number2;
                System.out.println(number1 + " - " + number2 + " = " + result);
            }
            case '/' -> {
                result = number1 / number2;
                System.out.println(number1 + " / " + number2 + " = " + result);
            }
            case '*' -> {
                result = number1 * number2;
                System.out.println(number1 + " * " + number2 + " = " + result);
        }
    }
}
}
