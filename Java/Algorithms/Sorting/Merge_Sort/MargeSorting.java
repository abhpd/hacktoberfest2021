package MargeSortTest;

/**
 *
 * @author Judha Maygustya
 */
public class MargeSorting {

    public void margeSort(int[] data) {
        this.sort(data, 0, data.length - 1);
    }

    public void marge(int data[], int left, int midle, int right) {
        int[] temp = new int[data.length];
        for (int i = left; i <= right; i++) {
            temp[i] = data[i];
        }
        int a = left;
        int b = midle + 1;
        int c = left;

        // ,e,bandingkan setiap bagian
        while (a <= midle && b <= right) {
            if (temp[a] <= temp[b]) {
                data[c] = temp[a];
                a++;
            } else {
                data[c] = temp[b];
                b++;
            }
            c++;
        }
        int s = midle - a;
        for (int i = 0; i <= s; i++) {
            data[c + i] = temp[a + i];
        }
    }

    // membagi menjadi 2 bagian dan d9i bagi kembali hingga tidak dapat digai kembali
    private void sort(int data[], int left, int right) {
        if (left < right) {
            int midle = (left + right) / 2;
            sort(data, left, midle);
            sort(data, midle + 1, right);
            marge(data, left, midle, right);
        }

    }

    public void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    // --------------------------------------------------------- //
}

//code by Judha Maygustya
