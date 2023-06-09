//5
//     * 
//    * * 
//   * * * 
//  * * * * 
// * * * * * 

package lecture1;

import java.util.Scanner;

public class Pattern11 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		int nst=1;
		int nsp=2*n-2;
		int row=1;
		while(row<=n) {
			for(int csp=1;csp<=nsp;csp++) {
				System.out.print(" ");
			}
			for(int cst = 1;cst<=nst;cst++) {
				System.out.print(" * ");
				System.out.print(" ");
			}
			System.out.println();
			row++;
			nsp-=2;
			nst++;
		}
	}

}
