package com.company;

public class LinearSearch {
    public static void main(String[] args) {
        int[] nums ={23, 45, 1, 2, 8, 19, -3, 16, -11, 28};
        int target = 19;
        int ans = linearSearch(nums,target);
        System.out.println(ans);
    }

    //search in the array : return the index of the item found
    //otherwise if item not found return -1

    static int linearSearch(int arr[], int target){
        if(arr.length ==0){
            return -1;
        }

        // run a for loop
        for(int index =0; index< arr.length; index++){
            //check for element at every index if it is equal to target
            int element  = arr[index];
            if(element == target){
                return index;
            }
        }
         // This line will execute if none of the return statements above have executed
        //Hence the target not found
        return -1;
    }
}
