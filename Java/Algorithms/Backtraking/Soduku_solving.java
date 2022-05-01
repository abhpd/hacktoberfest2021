/*
PROBLEM STATEMENT:
Given an nxn sized incomplete Sudoku in which 0 represents an empty cell. The task is to print it's solution.  
*/

import java.util.Scanner;
class Sudoku_Solver
{
	//A function to check whether a number between 1 to n can be placed at the specified cell or not
	public static boolean CanPlace(int[][] mat, int n, int i, int j, int num)
	{
		//check for rows and columns
		for(int x = 0; x < n; x++)
		{
			if(mat[x][j] == num || mat[i][x] == num)
				return false;
		}

		//check for the subgrid
		int root = (int)Math.sqrt(n);
		int sx = (i/root)*root;	//starting x coordinate of a subgrid
		int sy = (j/root)*root; //starting y coordinate of a subgrid
		for(int x = sx; x < sx+root; x++)
		{
			for(int y = sy; y < sy+root; y++)
			{
				if(mat[x][y] == num)
					return false;
			}
		}

		//else if it is possible to place num at mat[i][j], return true
		return true;
	}

	//A function to solve the Sudoku, once solved it prints the solution and returns true, otherwise false
	public static boolean SudokuSolver(int[][] mat, int n, int i, int j)
	{
		//base case
		if(i == n)
		{
			//print solution
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					System.out.print(mat[i][j]);
					System.out.print(" ");
				}
				System.out.print("\n");
			}
			return true;
		}

		//if a row ends, recursive call to next row
		if(j == n)
			return SudokuSolver(mat, n, i+1, 0);

		//if the cell is pre-filled, recursive call to the next cell
		if(mat[i][j] != 0)
			return SudokuSolver(mat, n, i, j+1);

		//Loop to fill any one of the number from 1 to n in a cell
		for(int num = 1; num <= n; num++)
		{
			//A function call to check whether it is possible to place num in the given cell or not
			if(CanPlace(mat, n, i, j, num))
			{
				mat[i][j] = num;
				//recursive call for the next cell
				boolean solvenext = SudokuSolver(mat, n, i, j+1);
				if(solvenext)
					return true;
			}
		}

		//if none of the number can be placed then, backtrack
		mat[i][j] = 0;
		return false;
	}

	// Driver Code
	public static void main(String[] args)
	{
		//Size input from user
		System.out.print("Enter size of the Sudoku: ");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println("Enter elements of Sudoku: ");    
		int mat[][] = new int[n][n];

		//Elements input from user
		for(int i = 0; i < n; i++)
		{            
			for(int j = 0; j < n; j++)
			{
				mat[i][j] = sc.nextInt();
			}
		}

		//function call to solve sudoku
		if(!SudokuSolver(mat, n, 0, 0))
			System.out.print("No Solution!");		
	}
}

/*
TEST CASES:
1.
Input:
Enter size of the Sudoku: 9
Enter elements of Sudoku:
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0 
0 8 7 0 0 0 0 3 1 
0 0 3 0 1 0 0 8 0 
9 0 0 8 6 3 0 0 5 
0 5 0 0 9 0 6 0 0 
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4 
0 0 5 2 0 6 3 0 0
Output: 
3 1 6 5 7 8 4 9 2 
5 2 9 1 3 4 7 6 8 
4 8 7 6 2 9 5 3 1 
2 6 3 4 1 5 9 8 7 
9 7 4 8 6 3 1 2 5 
8 5 1 7 9 2 6 4 3 
1 3 8 9 4 7 2 5 6 
6 9 2 3 5 1 8 7 4 
7 4 5 2 8 6 3 1 9 
2.
Input:
Enter size of the Sudoku: 9
Enter elements of Sudoku:
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0 
0 8 7 0 0 0 0 3 1 
0 0 3 0 1 0 4 8 0 
9 0 0 8 6 3 0 0 5 
0 5 0 0 9 0 6 0 0 
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4 
0 0 5 2 0 6 3 0 0
Output:
No Solution!
TIME COMPLEXITY:  O(9^(n*n)), as there will be 9 options from 1 to 9 to fill in an empty cell.
SPACE COMPLEXITY: O(n*n), where n denotes the size of Sudoku grid
*/