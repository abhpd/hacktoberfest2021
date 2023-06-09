package plusMinus;

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Plus Minus {

   
    static void plusMinus(int[] arr) { 
        int n= arr.length; 
  
        float positiveCount = 0; 
        float negativeCount = 0; 
        float zeroCount = 0; 
 
        for (int i = 0; i < n; i++) { 
            if (arr[i] > 0) { 
                positiveCount++; 
            } 
            else if (arr[i] < 0) { 
                negativeCount++; 
            } 
            else if (arr[i] == 0) { 
                zeroCount++; 
            } 
        } 
   
        System.out.printf("%1.6f \n ", positiveCount / n); 
        System.out.printf("%1.6f \n ", negativeCount / n); 
        System.out.printf("%1.6f \n ", zeroCount / n); 
        System.out.println(); 
        totalSum();
        System.out.println();
    } 
   
    public static float totalSum(){
       float sum = positiveCount + negativeCount + zeroCount;
       return sum;
    }
   
 
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        plusMinus(arr);

        scanner.close();
    }
}
