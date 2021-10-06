
/**
 * Author:  ARUN BALAJI R
 * Date:    30 June 2021 (Wednesday)
 */


import java.util.*;

//FIRST write code for shape
//then create code for numbers

public class NumberPattern{
	public static void main(String args[]){
		Solution s = new Solution();
		// s.similarOnePattern(5);
		// s.rowWiseIncNumber(5);
		// s.rowWiseDecNumber(5);
		// s.evenPattern(5);
		// s.alternateNum(5);
		// s.alternateSymbol(5);
		// s.numberDiamond(5);
		// s.numberDiamondIncDec(5);
		// s.columNumPrint(5);
		// s.ColNumHillpattern(5);
		// s.revColumnPattern(5);
		// s.decStartingValue(5);
		// s.numReverse(5);
		s.floydTriangle(5);
		
	}
}

class Solution{
	void similarOnePattern(int n){
		/*
			 1
			 1 1
			 1 1 1
			 1 1 1 1
			 1 1 1 1 1
		*/
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				System.out.print(" 1");
			}
			System.out.println();
		}
	}

	void rowWiseIncNumber(int  n){

		/*
			 1
			 2 2
			 3 3 3
			 4 4 4 4
			 5 5 5 5 5
		*/

		for(int i=1,p=1;i<=n;i++,p++){
			for(int j=1;j<=i;j++){
				//because we printing row
				// System.out.print(" "+i); to avoid confusing we can use seperate logic for nums
				System.out.print(p+" ");
			}
			System.out.println();
		}
		//similarly we can try all shapes by using this
	}

	void rowWiseDecNumber(int n){
		/*
		5 
		4 4 
		3 3 3 
		2 2 2 2 
		1 1 1 1 1 
		*/
		for(int i=1,p=n;i<=n;i++,p--){
			for(int j=1;j<=i;j++){
				System.out.print(p+" ");
			}
			System.out.println();
		}
		//similarly we can try all shapes by using this
	}

	void evenPattern(int n){
		/*
			0 
			2 2 
			4 4 4 
			6 6 6 6 
			8 8 8 8 8 
		*/
		for(int i=1,p=0;i<=n;i++,p+=2){
			for(int j=1;j<=i;j++){
				System.out.print(p+" ");
			}
			System.out.println();
		}
	}

	void alternateNum(int n){
		/*
			 1
			 2 2
			 1 1 1
			 2 2 2 2
			 1 1 1 1 1
		*/
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(i%2==0)
					System.out.print(" "+2);
				else
					System.out.print(" "+1);
			}
			System.out.println();
		}
	}


	void alternateSymbol(int n){
		/*
			 $ $ $ $ $
			 # # # #
			 $ $ $
			 # #
			 $
		*/
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				System.out.print((i%2==0) ? " #" : " $");
			}
			System.out.println();
		}
	}

	void numberDiamond(int n){

		/*
			  1 
	        2 2 2 
	      3 3 3 3 3 
	    4 4 4 4 4 4 4 
	  5 5 5 5 5 5 5 5 5 
	    6 6 6 6 6 6 6 
	      7 7 7 7 7 
	        8 8 8 
	          9
		*/

		int p=1;
		for(int i=1;i<n;i++,p++){
			for(int j=i;j<=n;j++){
				System.out.print("  ");
			}
			for(int j=1;j<=i;j++){
				System.out.print(p+" ");
			}
			for(int j=1;j<i;j++){
				System.out.print(p+" ");
			}
			System.out.println();
		}

		for(int i=1;i<=n;i++,p++){
			for(int j=1;j<=i;j++){
				System.out.print("  ");
			}
			for(int j=i;j<n;j++){
				System.out.print(p+" ");
			}
			for(int j=i;j<=n;j++){
				System.out.print(p+" ");
			}
			System.out.println();
		}
	}

	void numberDiamondIncDec(int n){
		/*
		   1
         2 2 2
       3 3 3 3 3
     4 4 4 4 4 4 4
   5 5 5 5 5 5 5 5 5
     4 4 4 4 4 4 4
       3 3 3 3 3
         2 2 2
           1
		*/

		int p=1;
		for(int i=1;i<n;i++,p++){
			for(int j=i;j<=n;j++){
				System.out.print("  ");
			}
			for(int j=1;j<i;j++){
				System.out.print(" "+p);
			}
			for(int j=1;j<=i;j++){
				System.out.print(" "+p);
			}
			System.out.println();
		}
		for(int i=1;i<=n;i++,p--){
			for(int j=1;j<=i;j++){
				System.out.print("  ");
			}
			for(int j=i;j<n;j++){
				System.out.print(" "+p);
			}
			for(int j=i;j<=n;j++){
				System.out.print(" "+p);
			}
			System.out.println();
		}
	}

	//COLUMN WISE PATTERN NUMBERS
	void columNumPrint(int n){
		/*
			
			1 
			1 2 
			1 2 3 
			1 2 3 4 
			1 2 3 4 5 		
	
		*/

		for(int i=1;i<=n;i++){
			int p=1;
			for(int j=1;j<=i;j++){
				System.out.print(p++ + " ");
			}
			System.out.println();
		}
	}

	void ColNumHillpattern(int n){
		/*
			          1 
			        1 2 3 
			      1 2 3 4 5 
			    1 2 3 4 5 6 7 
			  1 2 3 4 5 6 7 8 9 

		*/

		for(int i=1;i<=n;i++){
			int p=1;
			for(int j=i;j<=n;j++){
				System.out.print("  ");
			}
			for(int j=1;j<=i;j++){
				System.out.print(p++ +" ");
			}
			for(int j=1;j<i;j++){
				System.out.print(p++ +" ");
			}
			System.out.println();
		}
	}

	void revColumnPattern(int n){
		/*
		  5 4 3 2 1 
		    5 4 3 2 
		      5 4 3 
		        5 4 
		          5 
		*/
		for(int i=1;i<=n;i++){
			int p=n;
			for(int j=1;j<=i;j++){
				System.out.print("  ");
			}
			for(int j=i;j<=n;j++){
				System.out.print(p-- +" ");
			}
			System.out.println();
		}
	}

	void decStartingValue(int n){
		/*
		  5 4 3 2 1 
		    4 3 2 1 
		      3 2 1 
		        2 1 
		          1 
		*/
		for(int i=1,k=n;i<=n;i++,k--){
			int p=k;
			for(int j=1;j<=i;j++){
				System.out.print("  ");
			}
			for(int j=i;j<=n;j++){
				System.out.print(p-- +" ");
			}
			System.out.println();
		}
	}

	void numReverse(int n){
		/*
			      1 
		        1 2 1 
		      1 2 3 2 1 
		    1 2 3 4 3 2 1 
		  1 2 3 4 5 4 3 2 1 
		*/
		for(int i=1;i<=n;i++){
			int p=1;
			for(int j=i;j<=n;j++){
				System.out.print("  ");
			}
			for(int j=1;j<i;j++){
				System.out.print(p++ +" ");
			}
			for(int j=1;j<=i;j++){
				System.out.print(p-- +" ");
			}
			System.out.println();
		}
	}


	void floydTriangle(int n){

		/*
				
				 1
				 2 3
				 4 5 6
				 7 8 9 10
				 11 12 13 14 15

		*/


		int p=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				System.out.print(" "+p++);
			}
			System.out.println();
		}
	}


}