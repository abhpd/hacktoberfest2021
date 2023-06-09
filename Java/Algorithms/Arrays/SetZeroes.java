package com.yashpd;

// https://leetcode.com/problems/set-matrix-zeroes/ (Microsoft)

// this code will set all elements in the respective rows and columns in matrix to zero, in which a zero is located in matrix.
public class SetZeroes {
    public static void main(String[] args) {
        int[][] mat = {
                {1, 3, 5},
                {2, 0, 8},
                {4, 4, 6}
        };

        setZeroes(mat);
        print2D(mat);
    }

    static void setZeroes(int[][] matrix) {
        boolean firstrow = false;

        //checking for zero element and storing info in the matrix itself (in the first row and column).
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) {
                        firstrow = true;
                    } else {
                        matrix[i][0] = 0;
                    }
                    matrix[0][j] = 0;
                }
            }
        }

        // iterating from bottom right to top left and converting to zero.
        for (int i = matrix.length - 1; i >= 0; i--) {
            for (int j = matrix[i].length - 1; j >= 0; j--) {
                if (i == 0 && firstrow) {
                    matrix[i][j] = 0;
                } else if (i != 0 && (matrix[i][0] == 0 || matrix[0][j] == 0)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // to print out the matrix
    public static void print2D(int mat[][]) {
        // Loop through all rows
        for (int i = 0; i < mat.length; i++){
            // Loop through all elements of current row
            for (int j = 0; j < mat[i].length; j++){
                System.out.print(mat[i][j] + " ");
            }
            System.out.println();
        }

    }
}
