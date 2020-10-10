package InsertionSort;

/**
 * InsertionSort
 */
public class InsertionSort {
  public static void main(String[] args) {
    int[] originalArray = new int[10];

    for (int i = 0; i < originalArray.length; i++) {
      originalArray[i] = (int) (Math.random() * 15);
    }

    insertionSort(originalArray);

    for (int i = 0; i < originalArray.length; i++) {
      System.out.println(originalArray[i]);
    }
  }

  public static void insertionSort(int[] array) {
    for (int i = 1; i < array.length; i++) {
      int current = array[i];
      int j = i - 1;
      while (j >= 0 && current < array[j]) {
        array[j + 1] = array[j];
        j--;
      }
      array[j + 1] = current;
    }
  }
}