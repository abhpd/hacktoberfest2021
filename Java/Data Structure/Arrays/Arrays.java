import java.util.*;

class Solution {

   public int secondLargest(int[] array) {
      int n = array.length;
      int res = -1, largest = 0;
      for (int i = 1; i < n; i++) {
         if (array[i] > array[largest]) {
            res = largest;
            largest = i;

         } else if (array[i] < array[largest]) {
            if (res == -1 || array[i] > array[res]) {
               res = i;
            }
         }
      }
      return array[res];
   }
}

class Arrays {

   public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);
      System.out.print("Enter the size of array");
      int n = scanner.nextInt();
      int[] array = new int[n];
      for (int i = 0; i < n; i++) {
         array[i] = scanner.nextInt();
      }
      Solution sc = new Solution();
      System.out.print("The second largest element is " + sc.secondLargest(array));
   }
}
