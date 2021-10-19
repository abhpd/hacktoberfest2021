package com.company;

import java.util.Random;

import static java.lang.Math.*;

public class RandomNumberGenerator {
    public static void main(String[] args) {
        //Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.
        //A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).
        Random random = new Random();
        for(int i =0; i<1000; i++){
            int num = random.nextInt(500);
            System.out.print(num+ " ");
        }
    }
}
