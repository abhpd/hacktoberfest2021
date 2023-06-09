// import the Class
import java.util.Arrays;
import java.util.Scanner;

class Main {

  // create an object of scanner
  // to take input from the user
  Scanner input = new Scanner(System.in);

  // method to perform bubble sort
  void bubbleSort(int array[]) {
    int size = array.length;

    // for ascending or descending sort
    System.out.println("Choose Sorting Order:");
    System.out.println("1 for Ascending \n2 for Descending");
    int sortOrder = input.nextInt();

    // run loops two times
    // first loop access each element of the array
    for (int i = 0; i < size - 1; i++)

      // second loop performs the comparison in each iteration
      for (int j = 0; j < size - i - 1; j++)

        // sort the array in ascending order
        if (sortOrder == 1) {
          // compares the adjacent element
          if (array[j] > array[j + 1]) {

            // swap if left element is greater than right
            int temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
          }
        }

        // sort the array in descending order
        else {
          // compares the adjacent element
          if (array[j] < array[j + 1]) {

            // swap if left element is smaller than right
            int temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
          }
        }

  }

  // driver code
  public static void main(String args[]) {

    // create an array
    int[] data = { -2, 45, 0, 11, -9 };

    // create an object of Main class
    Main bs = new Main();

    // call the method bubbleSort using object bs
    // pass the array as the method argument
    bs.bubbleSort(data);
    System.out.println("Sorted Array in Ascending Order:");

    // call toString() of Arrays class
    // to convert data into the string
    System.out.println(Arrays.toString(data));
  }
}