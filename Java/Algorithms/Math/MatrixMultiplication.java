/*First Matrix:
        2	2	3
        3	2	4
        1	3	4
Second Matrix:
        3	5	7
        4	2	1
        3	2	1

Output: Multiplication of Matrices
        23	20	19

        29	27	27

        27	19	14  */


public class MatrixMultiplication {
    public static void main(String[] args) {
        int[][] arr1 = {{2, 2, 3}, {3, 2, 4}, {1, 3, 4}}; //First Matrix
        int[][] arr2 = {{3, 5, 7}, {4, 2, 1}, {3, 2, 1}}; //Second Matrix
        int[][] answer = new int[arr1.length][arr2[0].length];

        for (int i = 0; i < answer.length; i++) {
            for (int j = 0; j < answer[i].length; j++) {
                int sum=0;
                for (int k = 0; k < arr2.length; k++) {
                    sum+=arr1[i][k]* arr2[k][j];
                }
                answer[i][j]=sum;
            }
        }

        System.out.println("First Matrix");
        printArray(arr1);
        System.out.println("Second Matrix");
        printArray(arr2);
        System.out.println("Multiplication of matrices");
        printArray(answer);
    }

    //Print the array
    static void printArray(int[][] arr){
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.print(arr[i][j]+"\t");
            }
            System.out.println("\n");
        }
    }
}