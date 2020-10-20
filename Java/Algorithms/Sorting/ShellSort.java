package ShellSort;

public class shellsort {
    public static void main() {

        int[] arr = {20, 35, -15, 7, 55, 1, -22};
        for (int gap = arr.length / 2; gap > 0; gap = gap / 2) {
            for (int i = gap; i < arr.length; i++) {
                int newelement = arr[i];
                int j = i;
                while (j >= gap && arr[j - gap] > newelement) {
                    arr[j] = arr[j - gap];
                    j=j-gap;
                }
                arr[j]=newelement;
            }
        }


    }
}
