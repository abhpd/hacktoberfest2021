package Pepcoding;

import java.util.Scanner;

public class TowerOfHanoi {
    public static void main(String[] args) {
        Scanner s= new Scanner(System.in);
        int n= s.nextInt();
        int t1= s.nextInt();
        int t2= s.nextInt();
        int t3= s.nextInt();
        toh(n, t1, t2, t3);
    }

    public static void toh(int n, int t1, int t2, int t3){
        //t1- source
        //t2- helper
        //t3- destination
        if (n == 0){
            return;
        }
        toh(n - 1, t1, t3, t2);
        System.out.println(n + "[" + t1 + " -> " + t2 + "]");
        toh(n - 1, t2, t1, t3);
    }
}
