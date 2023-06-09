import java.util.Arrays;
import java.util.Scanner;

public class CombineTwoArrays {
    public static void main(String[] args) {
        int n, y;
        Scanner s = new Scanner(System.in);
        System.out.print("Enter no. of elements you want in array 1 :");
        n = s.nextInt();

        int array1[] = new int[n];
        System.out.println("Enter all the elements:");
        for(int i = 0; i < n; i++)
        {
            array1[i] = s.nextInt();  
        }

        System.out.print("Enter no. of elements you want in array 2 :");
        y = s.nextInt();

        int array2[] = new int[y];
        System.out.println("Enter all the elements:");
        for(int i = 0; i < y; i++)
        {
            array2[i] = s.nextInt();
        }


        s.close();

        System.out.println("Combination of two arrays :");
        int aLen = array1.length;
        int bLen = array2.length;
        int[] result = new int[aLen + bLen];

        System.arraycopy(array1, 0, result, 0, aLen);
        System.arraycopy(array2, 0, result, aLen, bLen);

        System.out.println(Arrays.toString(result));
}
}
