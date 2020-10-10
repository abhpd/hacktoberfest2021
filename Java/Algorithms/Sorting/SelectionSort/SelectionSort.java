package SelectionSort;

/**
 * SelectionSort
 */
public class SelectionSort {
  public static void main(String[] args) {
    int[] originalArray = new int[10];

    for (int i = 0; i < originalArray.length; i++) {
      originalArray[i] = (int) (Math.random() * 15);
    }

    selectionSort(originalArray);

    for (int i = 0; i < originalArray.length; i++) {
      System.out.println(originalArray[i]);
    }
  }

  public static void selectionSort(int[] array) {
    for (int i = 0; i < array.length - 1; i++) {
      int k = i;
      for(int j = i + 1; j < array.length; j++) {
        if (array[j] < array[k]) {
          k = j;
        }
      }
      int temp = array[k];
      array[k] = array[i];
      array[i] = temp;
    }
  }
}