
/*
 * Rotation of array elements K times
 * */

import java.util.Scanner;

public class ArrayRotation {


    public static  void rotateArray(int[] arr, int N, int K){

        K = K % N;
        reverseArray(arr,0,N);

        reverseArray(arr,0,K);

        reverseArray(arr,K,N);

    }

    public static void reverseArray(int[] arr, int start, int end) {
        for (int i = start; i < end/2 ; i++) {
            int temp=arr[i];
            arr[i]=arr[end-i-1];
            arr[end-i-1]=temp;
        }
    }

    public static void main(String[] args) {

        Scanner sc =  new Scanner(System.in);
        int K=0,N = 0;
        K=sc.nextInt();
        N=sc.nextInt();
        int[] arr = new int[N];
        for(int i=0; i<N; i++){
            arr[i]= sc.nextInt();
        }
        rotateArray(arr,N,K);

        for (int i = 0; i < N; i++)
            System.out.print(arr[i] + " ");
    }


}
