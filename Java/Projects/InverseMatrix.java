import java.util.Scanner;

public class InverseMatrix {

    public static void main(String[] args) {
        Scanner sc =  new Scanner(System.in);

        //find the inverse of 3 * 3 matrix


        int matrix_2BY2[][] = new int[3][3];

        //get elements to the matrix
        System.out.println("Enter elements to the first row");
        for(int i = 0; i<=0; i++){ //only for first row
            for(int j=0; j<3; j++){
                matrix_2BY2[i][j] = sc.nextInt();
            }
        }
        System.out.println("Enter elements to the second row");
        for(int i = 1; i<=1; i++){ //only for second row
            for(int j=0; j<3; j++){
                matrix_2BY2[i][j] = sc.nextInt();
            }
        }
        System.out.println("Enter elements to the third row");
        for(int i = 2; i<=2; i++){ //only for third row
            for(int j=0; j<3; j++){
                matrix_2BY2[i][j] = sc.nextInt();
            }
        }

        //printing the matrix
        // printMatrix(matrix_2BY2);

        //finding the inverse of the matrix
        findinverse(matrix_2BY2);

    }

    public static void findinverse(int[][] matrix_2BY2) {

        //finding the determinnat
        int det = determinant(matrix_2BY2);
        //System.out.println(det + "\n");

        //getting the transpose matrix
        int t_matrix[][] = transpose_matrix(matrix_2BY2);

        //determinant of each 2 by 2 matrix
        int det2[][] = determinant_of_each_2(t_matrix);

        System.out.println();
        //adjugate multiply my its sign matrix
        int adj[][] = adjugate_matrix(det2);
        //printMatrix(adj);
        System.out.println();

        //find the inverse matrix finally
        inverseAtLast(adj, det);



    }

    private static void inverseAtLast(int[][] adj, int det) {

        double finalInverseM[][] = new double[3][3];

        for (int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                finalInverseM[i][j] = Double.valueOf(adj[i][j])  / Double.valueOf(det);
                System.out.print(finalInverseM[i][j] + " ");
            }
            System.out.println();
        }

        for (int i=0; i<3;i++){
            for (int j=0; j<3; j++){
                //System.out.print(finalInverseM[i][j] + " ");
            }
            //System.out.println();
        }

    }

    private static int[][] determinant_of_each_2(int[][] t) {

        int det2[][] = new int[3][3];
        det2[0][0] = t[1][1]*t[2][2] - t[1][2]*t[2][1]; //
        det2[0][1] = t[1][0]*t[2][2] - t[1][2]*t[2][0];
        det2[0][2] = t[1][0]*t[2][1] - t[1][1]*t[2][0];
        det2[1][0] = t[0][1]*t[2][2] - t[0][2]*t[2][1];//
        det2[1][1] = t[0][0]*t[2][2] - t[0][2]*t[2][0];
        det2[1][2] = t[0][0]*t[2][1] - t[0][1]*t[2][0];//
        det2[2][0] = t[0][1]*t[1][2] - t[0][2]*t[1][1];
        det2[2][1] = t[0][0]*t[1][2] - t[0][2]*t[1][0];
        det2[2][2] = t[0][0]*t[1][1] - t[0][1]*t[1][0];

        return det2;
    }

    private static int[][] adjugate_matrix(int[][] adj) {

        int t[][] = new int[3][3];

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i==0){ //if the first row
                    if(j==1){
                        t[i][j] = adj[i][j] * (-1);
                    }else {
                        t[i][j] = adj[i][j];
                    }
                }else if(i==1){ //second row
                    if(j==0 || j==2){
                        t[i][j] = adj[i][j] * (-1);
                    }else {
                        t[i][j] = adj[i][j];
                    }
                }else if(i==2){ //third row
                    if(j==1){
                        t[i][j] = adj[i][j] * (-1);
                    }else {
                        t[i][j] = adj[i][j];
                    }
                }
            }
        }
        return t;
    }

    private static int[][] transpose_matrix(int[][] matrix_2BY2){

        int transposeMatrics[][] = new int[3][3];
        transposeMatrics[0][0] = matrix_2BY2[0][0]; //
        transposeMatrics[0][1] = matrix_2BY2[1][0]; //
        transposeMatrics[0][2] = matrix_2BY2[2][0];
        transposeMatrics[1][0] = matrix_2BY2[0][1]; //
        transposeMatrics[1][1] = matrix_2BY2[1][1]; //
        transposeMatrics[1][2] = matrix_2BY2[2][1];
        transposeMatrics[2][0] = matrix_2BY2[0][2]; //
        transposeMatrics[2][1] = matrix_2BY2[1][2]; //
        transposeMatrics[2][2] = matrix_2BY2[2][2];

        return transposeMatrics;
    }

    public static int determinant(int[][] m) {
        int det = m[0][0]* (m[1][1]*m[2][2] - m[1][2]*m[2][1]) -
                m[0][1]* (m[1][0]*m[2][2] - m[1][2]*m[2][0]) +
                    m[0][2]* (m[1][0]*m[2][1] - m[1][1]*m[2][0]);
        return  det;
    }

    public static void printMatrix(int[][] matrix_2BY2) {
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                System.out.print(matrix_2BY2[i][j] + " ");
            }
            System.out.println();
        }

    }



}
