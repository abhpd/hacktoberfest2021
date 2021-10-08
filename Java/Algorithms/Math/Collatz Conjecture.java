/*******
 * SHaDeX0
 * 08 - 10 - 2021 (Friday)
 * Collatz conjecture also called '3x+1 Problem'
 */

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class _3xPlus1 {
    public static void main(String[] args) {

        System.out.println("Enter a number:");

        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();                    //Input number to find its 3x + 1 expansion
        ArrayList<Integer> maxMin = new ArrayList<>();  //To find max and min value of 'num's 3x + 1 expansion

        System.out.println("Its 3x + 1 expansion:");

        while (num != 1) {
            System.out.print(num + " ");                //Printing the expansion
            maxMin.add(num);                            //Adding 'num' to the ArrayList

            if (num % 2 == 0) {                         //If 'num' is even perform even operation
                num = evenOperation(num);
            } else {                                    //If 'num' is odd perform odd operation
                num = oddOperation(num);
            }
        }
        System.out.print(num + " ");                    //Printing the last number as after the operations, num = 1 always
        maxMin.add(num);                                //Adding 'num' = 1 to the ArrayList

        System.out.println("\nMax value: " + Collections.max(maxMin) + //Displaying Max value in the expansion,
            "\nMin Value: " + Collections.min(maxMin) +                //Min value in the expansion and
            "\nNumber of iterations: " + maxMin.size());               //Number of iterations 'num' took to reduce to 1
    }

    private static int evenOperation(int num) {         //Function for doing the even operation
        return (num / 2);                               //Halving 'num'
    }

    private static int oddOperation(int num) {          //Function for doing the odd operation
        return ((3 * num) + 1);                         //Multiplying 'num' and incrementing it by 1
    }
}
