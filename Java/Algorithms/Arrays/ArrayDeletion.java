import java.util.Arrays;
import java.util.Objects;
import java.util.Random;

/**
 * This class contains various methods pertaining to the deletion of elements
 * within an {@link Integer} array. All solutions to the methods can be found in
 * the {@link Solution} class. If issues are present within this class, follow
 * the contribution guidelines posted within the <a href=
 * "https://github.com/abhpd/hacktoberfest2021/blob/main/CONTRIBUTING.md">CONTRIBUTING.md
 * </a>file.
 * 
 * @author Arun Balaji R
 * @author Dylan Middendorf
 */

public class ArrayDeletion {

    public static void main(String args[]) {
        Solution s = new Solution();
        int[] arr = s.generateArray(6, 10);

        s.printArray(arr);
        s.deleteLast(arr, false);
        s.printArray(arr);
        s.deleteStart(arr, false);
        s.printArray(arr);
        s.deleteAt(arr, 2, false);
        s.printArray(arr);

    }
}

class Solution {

    int[] deleteLast(int arr[], boolean trueDeleation) {
        Objects.requireNonNull(arr);

        if (trueDeleation) {
            int[] newArr = new int[arr.length - 1];
            System.arraycopy(arr, 0, newArr, 0, newArr.length);
            return newArr;
        } else {
            arr[arr.length - 1] = 0;
            return arr;
        }
    }

    int[] deleteStart(int arr[], boolean trueDeleation) {
        Objects.requireNonNull(arr);

        if (trueDeleation) {
            int[] newArr = new int[arr.length - 1];
            System.arraycopy(arr, 1, newArr, 0, newArr.length);
            return newArr;
        } else {
            for (int i = 0, j = arr.length - 1; i < j; ++i)
                arr[i] = arr[i + 1];
            deleteLast(arr, false);
            return arr;
        }
    }

    int[] deleteAt(int arr[], int pos, boolean trueDeleation) {
        Objects.requireNonNull(arr);
        if (pos >= arr.length)
            throw new IndexOutOfBoundsException("Index " + pos + "out of bounds for length " + arr.length);

        if (trueDeleation) {
            int[] newArr = new int[arr.length - 1];
            System.arraycopy(arr, 0, newArr, 0, pos);
            System.arraycopy(arr, pos + 1, newArr, pos, newArr.length - pos);
            return newArr;
        } else {
            for (int i = pos; i < arr.length - 1; ++i)
                arr[i] = arr[i + 1];
            deleteLast(arr, false);
            return arr;
        }
    }

    int[] generateArray(int size, int magnitude) {
        int[] a = new int[size];
        Random r = new Random();
        for (int i = 0; i < size; ++i)
            a[i] = r.nextInt(magnitude);
        Arrays.sort(a);
        return a;
    }

    void printArray(int arr[]) {
        Objects.requireNonNull(arr);

        for (int i : arr)
            System.out.print(i + " ");
        System.out.println();
    }
}