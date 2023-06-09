import java.util.Scanner;

public class NQueenProblem {

	public static void main(String[] args) {
        
		Scanner sc = new Scanner(System.in);
		int row = 0;
		System.out.println("Enter number rows: ");
		int N = sc.nextInt();
		int[][] board = new int[N][N];
		solveNQueen(board, row, N);
		System.out.println("Total possible ouptut = " + count);
		sc.close();

	}
	static int count = 0;
	public static boolean solveNQueen(int[][] board, int row, int N) {
		if(row == N) {				//Base case
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					if(board[i][j] == 1)
						System.out.print("Q ");
					else System.out.print("_ ");
				}
				System.out.println();
			}
			count++;
			System.out.println();
			System.out.println();
			
			return false;      //result is false so that we can get all possible outputs  
		}
		
		for(int col = 0; col < N; col++) {    //traverse through each column
			if(isSafe(board, row, col, N)) {    //checks for cell
				board[row][col] = 1;
				
				if(solveNQueen(board, row+1, N))   //checks for next row
					return true;
				board[row][col] = 0;      //backtracking
			}	
		}
		
		return false;
	}
	
	public static boolean isSafe(int[][] board, int row, int col, int N) {
		for(int i = 0; i < row; i++) 
			if(board[i][col] == 1)    //checks for upper rows
				return false;
		
		for(int i = row, j = col; i >= 0 && j < N; i--, j++)
			if(board[i][j] == 1)     //checks for upper right diagonal
				return false;
		
		for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
			if(board[i][j] == 1)     //checks for upper left diagonal
				return false;
		
		return true;       	//if all loop gets terminated without any result then return true
			
	}

}
