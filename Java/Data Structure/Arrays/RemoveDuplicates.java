import java.util.*;

public class RemoveDuplicates {

    public static int removeArray(int[] array) {
        int res = 1, n = array.length;
        for (int i = 1; i < n; i++) {
            if (array[i] != array[res - 1]) {
                array[res] = array[i];
                res++;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of array");
        int n = scanner.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        int num = removeArray(array);
        for (int i = 0; i < num; i++) {
            System.out.print(array[i] + " ");
        }
    }
}
