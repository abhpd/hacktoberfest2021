//7
//   *
//  ***
// *****
//*******
// *****
//  ***
//   *
   
package lecture1;

import java.util.Scanner;

public class Pattern18 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		int nsp=n/2;
		int nst=1;
		
//		rows
		int row=1;
		while(row<=n) {
//			work
			
//			space work
			int csp=1;
			while(csp<=nsp) {
				System.out.print(" ");
				csp++;
			}
//			star work
			int cst=1;
			while(cst<=nst) {
				System.out.print("*");
				cst++;
			}
//			prep
			System.out.println();
			if(row<=n/2) {
				nsp--;
				nst+=2;
			}else {
				nsp++;
				nst-=2;
			}
			row++;
		}
	}

}
