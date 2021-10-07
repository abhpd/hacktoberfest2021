
/*
link to leetcode question :
https://leetcode.com/problems/find-smallest-letter-greater-than-target/

Question :
Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.

Note that the letters wrap around.
For example, if target == 'z' and arr == ['a', 'b'], the answer is 'a'
*/

public class SmallestLetter {
    public static void main(String[] args) {
        char[] arr = {'c','f','j'};
        char target = 'z';
        char ans = nextGreatestLetter(arr, target);
        System.out.println(ans);
    }

    static char nextGreatestLetter(char[] letters, char target) {

        int start = 0;
        int end = letters.length-1;
        int middle=0;
        while(start<=end)
        {
            //find the middle element
            middle = (start + end)/2;
            if(target<letters[middle]){
                end = middle-1;
            }
            else{
                start = middle+1;
            }
        }
        return letters[start% letters.length];
    }
}
