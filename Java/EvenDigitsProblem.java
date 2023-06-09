package com.company;

public class EvenDigitsProblem {
    // Even digits problem- Given an array of integers. Return how many of them contain an even number of digits.
    public static void main(String[] args) {
        int[] nums = {12,345,2,6,7896};
        System.out.println(findNumbers(nums));
        System.out.println(digits(5678));
    }

    static int findNumbers(int[] nums){
        int count =0;
        for(int num:nums){
            if(even(num)){
                count++;
            }
        }
        return count;
    }

    // function to check whether a number contains even digits or not
    static boolean even(int num){
        int numberOfDigits = digits(num);
        /*
        if(numberOfDigits % 2==0){
          return true;
        )
        return false;
         */
        return numberOfDigits% 2==0;
    }

    // count number of digits( int num)
    static int digits(int num){
        int count = 0;
        if(num <0){
            num = num*-1;
        }
        if(num ==0){
            return 1;
        }
        while(num>0){
            count++;
            num /= 10;
        }
        return count;
    }
}

}
