package BubbleSort;

/**
 * BubbleSort
 */
public class BubbleSort {
  public static void main(String[] args) {
    int[] originalArray = new int[10];

    // Here Im making
    for (int i = 0; i < originalArray.length; i++) {
      originalArray[i] = (int) (Math.random() * 15);
    }

    bubbleSort(originalArray);

    for (int i = 0; i < originalArray.length; i++) {
      System.out.println(originalArray[i]);
    }
  }

  public static void bubbleSort(int[] a) {

    boolean swapped;
    int temp;

    for (int j = 0; j < a.length; j++) {

      swapped = false;

      for (int i = 0; i < a.length - 1; i++) {
        if (a[i] >= a[i + 1]) {
          temp = a[i];
          a[i] = a[i + 1];
          a[i + 1] = temp;
        }
      }

      // if you did not swap for a particular value of i, it means the array is sorted
      // hence stop the program
      if (!swapped) {
        break;
      }
    }
  }
}