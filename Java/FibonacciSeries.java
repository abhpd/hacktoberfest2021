/* This program uses a recursive function to find the number present at the given position in the Fibonacci series */

import java.util.*;

public class FibonacciSeries {
   public static long fib(long n) {
      if ((n == 0) || (n == 1))
         return n;
      else
         return fib(n - 1) + fib(n - 2);
   }
   public static void main(String[] args)
   {
      Scanner sc=new Scanner(System.in);
      System.out.println("Please Enter the Position:");
      int pos=sc.nextInt();
      if (pos == 1)
            System.out.println("The " + pos + "st fibonacci number is: " + fib(pos));
      if (pos == 2)
            System.out.println("The " + pos + "nd fibonacci number is: " + fib(pos));
      if (pos == 3)
            System.out.println("The " + pos + "rd fibonacci number is: " + fib(pos));
      else     
            System.out.println("The " + pos + "th fibonacci number is: " + fib(pos));
   }
}
