
/**
 * Author:  ARUN BALAJI R
 * Date:    30 June 2021 (Wednesday)
 */


import java.util.*;
public class StarPattern{
	public static void main(String args[]){
		Solution s = new Solution();
		// s.printSquare(5);

		// s.printIncTriangle(5);

		// s.printDecTriangle(5);

		// s.printRightTriangle(5);

		// s.printLeftTriangle(5);

		// s.printHillPattern(5);

		// s.printReverseHill(5);

		s.printReverseHillFor(5);
	}
}

class Solution{
	void printSquare(int n){
		/*
		* * * * *
		* * * * *
		* * * * *
		* * * * *
		* * * * *

		*/
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				System.out.print(" *");
			}
			System.out.println();
		}
	}

	//TWO BASIC  BUILDING BLOCKS
	// 1 . Increasing Triangle
	// 2. Decreasing Triangle


	void printIncTriangle(int n){
	/*
	 	*
 		* *
 		* * *
 		* * * *
 		* * * * *
	*/
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				System.out.print(" *");
			}
			System.out.println();
		}
	}

	void printDecTriangle(int n){
		 /*
		 * * * * *
		 * * * *
		 * * *
		 * *
		 *

		 */

		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				System.out.print(" *");
			}
			System.out.println();
		}
	}

	//BASED ON THIS TWO TRIANGLES WE CAN ABLE TO MAKE ANY TRIANGLE PATTERN

	//RIGHT TRIANGLE

	/*
	     	*
	   	  * *
	    * * *
	  * * * *
	* * * * *

	*/

	//here if we observe there is two triangles.
	// 1(decreasing triangel with spaces)
	// 2(increasing triangle with stars)

	void printRightTriangle(int n){
		for(int i=1;i<=n;i++){
			//code for decreasing space
			for(int j=i;j<=n;j++){
				System.out.print("  ");
			}
			//code for increasing star
			for(int j=1;j<=i;j++){
				System.out.print(" *");
			}
			System.out.println();
		}

	}

	void printLeftTriangle(int n){
		/*
			   * * * * *
     		   * * * *
       		   * * *
          	   * *
           	   *
		*/
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				System.out.print("  ");
			}
			for(int j=i;j<=n;j++){
				System.out.print(" *");
			}
			System.out.println();
		}
	}

	void printHillPattern(int n){
		/*
			           *
			         * * *
			       * * * * *
			     * * * * * * *
			   * * * * * * * * *
		*/
		for(int i=1;i<=n;i++){
			//decreasing space
			for(int j=i;j<=n;j++){
				System.out.print("  ");
			}
			//note : here j<i to reduce one extra column
			//increasing  stars
			for(int j=1;j<i;j++){
				System.out.print(" *");
			}
			for(int j=1;j<=i;j++){
				System.out.print(" *");
			}
			System.out.println();
		}
	}
	//similarly  we can achieve any pattern in satrs

	void printReverseHill(int n){

		/*

		* * * * * * * * *
    	 * * * * * * *
           * * * * *
         	 * * *
           	   *
		*/

		for(int i=1;i<=n;i++){
			//increasing spcae
			for(int j=1;j<=i;j++){
				System.out.print("  ");
			}

			//decreasing stars
			for(int j=i;j<=n;j++){
				System.out.print(" *");
			}

			//deccreasing star(overlap reduction j<n)
			for(int j=i;j<n;j++){
				System.out.print(" *");
			}
			System.out.println();
		}
	}

	//we can also use condition for avoiding multiple time for loop printing within single
	//for loop

	void printReverseHillFor(int n){
		//here i reduced one for by using nested for

		/*

		* * * * * * * * *
    	 * * * * * * *
           * * * * *
         	 * * *
           	   *
		*/

		//same by using nested forloop
		// (preferable for big patterns like)
		for(int i=1;i<=n;i++){
			//increasing spcae
			for(int j=1;j<=i;j++){
				System.out.print("  ");
			}
			for(int k=0;k<=1;k++){
				//decreasing stars
				for(int j=i;j<n+k;j++){
					System.out.print(" *");
				}
			}
			System.out.println();
		}
	}

/*	Enter the number of rows you want to print: 5
* * * * *
 * * * *
  * * *
   * *
    *
    *
   * *
  * * *
 * * * *
* * * * *
    */
		import java.util.Scanner;
		public class sandGlassPattern
		{
		public static void main(String[] args)
		{
		int i, j, k, n;
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number of rows ");
		n = sc.nextInt();
		for (i= 0; i<= n-1 ; i++)
		{
		for (j=0; j<i; j++)
		{
		System.out.print(" ");
		}
		for (k=i; k<=n-1; k++)
		{
		System.out.print("*" + " ");
		}
		System.out.println("");
		}
		for (i= n-1; i>= 0; i--)
		{
		for (j=0; j<i; j++)
		{
		System.out.print(" ");
		}
		for (k=i; k<=n-1; k++)
		{
		System.out.print("*" + " ");
		}
		System.out.println("");
		}
		sc.close();
		}
		}


}
