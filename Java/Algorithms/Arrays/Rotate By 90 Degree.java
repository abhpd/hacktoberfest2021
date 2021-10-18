// 1. You are given a number n, representing the number of rows and number of columns.
// 2. You are given n*n numbers, representing elements of 2d array a.
// 3. You are required to rotate the matrix by 90 degree clockwise and then display the contents using display function.
// *Note - you are required to do it in-place i.e. no extra space should be used to achieve it .*
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scan = new Scanner(System.in);
        int row = scan.nextInt();
        
        int arr[][] =  new int[row][row];
        for(int i=0;i<row;i++){
            for(int j=0;j<row;j++){
                arr[i][j] = scan.nextInt();
            }
        }
        int n=row,i=0,j=0,temp=0;
        for( i=0;i<n/2;i++)
        {
            for( j=i;j<n-1-i;j++)
            {
                temp=arr[0+i][j];
                arr[i][j]=arr[n-1-j][i];
                arr[n-1-j][i]=arr[n-1-i][n-1-j];
                arr[n-1-i][n-1-j]=arr[j][n-1-i];
                arr[j][n-1-i]=temp;
            }
        }
        display(arr);
        
    }

    public static void display(int[][] arr){
        for(int i = 0; i < arr.length; i++){
            for(int j = 0; j < arr[0].length; j++){
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

}