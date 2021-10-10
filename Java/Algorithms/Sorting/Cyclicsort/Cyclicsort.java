// Sorting the numbers in the array using cyclic sort
/*
   When the numbers are given in the range from 1 to length of the array and asked for sorting
   we can use cyclic sort
   For example : arr = {1,4,5,2,3}
   In the above example, we can see that the length of the array is 5 and the numbers are in the
   range from 1 to 5.
   Time complexity of the Cyclic sort is O(n)
   Steps :
   1. Loop from the start index
   2. Choose the first element in the array and check whether it is in the correct index or not
   3. If it is not in the correct index, swap it with the correct index
   4. If it is in the correct index, increment the loop and check the element in the next index
   5. Loop until the last element in the array



   Questions related to Cyclic sort were asked in Google, Amazon and some other product-based
   companies.
 */

import java.util.*;
public class Cyclicsort {
    public static void main(String[] args) {
        int[] arr = {2,3,1,4,6,5};
        int[] arr2 = {1,4,5,2,3};
        System.out.println(Arrays.toString(cyclicsort(arr))); // printing the sorted array
        System.out.println(Arrays.toString(cyclicsort(arr2)));
    }
    public static int[] cyclicsort(int[] nums)
    {
        int i = 0;
        while(i < nums.length) {
            int correct = nums[i] - 1; // as the index starts from 0 and the numbers start
            // from 1 so index of 1 will be 0
            if (nums[i] != nums[correct])// If the number is not in the correct index,
            // swap it's present index with its correct index
            {
                int temp = nums[i];
                nums[i] = nums[correct];
                nums[correct] = temp;
            } else { // If the element is in the correct index, increment i
                i++;
            }
        }
        return nums;
    }
}
