package BubbleSortRecursive;

import java.util.Arrays;

/**
 * Bubble sort recursive implementation
 */
public class BubbleSortRecursive {

  public static void main(String[] args){
    final int maxLength = 10;
    int[] array = new int[maxLength];

    for (int i = 0; i < maxLength; i++) {
      array[i] = (int)(Math.random() * 1000);
    }

    bubbleSort(array, array.length);

    System.out.println("Sorted array: "); // NOSONAR
    System.out.println(Arrays.toString(array)); // NOSONAR
  }

  /**
   * Bubble sort recursive.
   * 
   * @param array array to bubble sort
   * @param length length of the array
   */
  public static void bubbleSort(final int[] array, final int length){
    if(1 == length){
      return;
    }

    for(int i = 0; i <  length - 1 ; i++) {
      if(array[i] > array[i + 1]) {
        final int aux = array[i];
        array[i] = array[i + 1];
        array[i + 1] = aux;
      }
    }
    bubbleSort(array, length - 1);
  }
}