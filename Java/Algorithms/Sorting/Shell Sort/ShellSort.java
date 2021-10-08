package com.company;

import java.util.Arrays;

public class ShellSort {
    public static void main(String[] args) {

        int[] nums = {50, 34, 78, 44, 8, 90, 21, 1, 30};
        int n = nums.length;
        int temp;
        int j;

        for (int gap = n/2; gap >= 1; gap /= 2) {

            for (int i = gap; i < n; i++) {

                temp = nums[i];

                for (j = i; j >= gap && nums[j-gap] > temp; j -= gap) {

                    nums[j] = nums[j - gap];
                }
                nums[j] = temp;
            }
        }

        System.out.println(Arrays.toString(nums));

    }
}
