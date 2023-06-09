/* Patter for N = 4
 	      1
 	    12
 	  123
 	1234
*/

/* Let's think the approach
 	1. N number of rows
 	2. ith row will have (2*(n-i) spaces, i increasing numbers- starts from 1, i-1 spaces) 
 	3. need to print spaces, increasing numbers and spaces
*/

package patterns2;

import java.util.Scanner;

public class MirrorPattern {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		
		int i = 1;
		while (i <= n) {
			int spaces = 1;
			while (spaces <= (2*(n-i))) {
				System.out.print(" ");
				spaces++;
			}
			int j = 1;
			int p = 1;
			while (j <= i) {
				System.out.print(p);
				p++;
				j++;
			}
			System.out.println();
			i++;
		}

	}

}
