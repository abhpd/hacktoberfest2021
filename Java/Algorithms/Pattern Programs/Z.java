
/**
 * Author:  ARUN BALAJI R
 * Date:    	25 August 2021 (Wednesday)
 */


import java.util.*;
public class Z{
	public static void main(String args[]){
		int n=6;
		int count = 0;
		for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == n - 1 - i) {
                System.out.print(" "+count++);
            } else {
                System.out.print("  ");
            }
        }
        System.out.println();
    }
	}
}

