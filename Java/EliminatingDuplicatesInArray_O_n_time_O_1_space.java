import java.util.Scanner;
public class Solution {
    public static int removeDuplicates(int[] nums) {
        int unique=0;
        for(int i=0;i<nums.length-1;i++)
        {
            if(nums[i+1]>nums[unique])
            {
                nums[unique+1]=nums[i+1];
                unique++;
            }
        }
        return unique+1;
    }
    public static void main(String[] args) {
	Scanner scn = new Scanner(System.in);
	System.out.print("Enter number of elements: ");
	int n = scn.nextInt();
	int[] arr = new int[n];
  	System.out.println("Enter elements separated by space: ");
	for(int i=0; i<n; i++)
	{
		arr[i] = scn.nextInt();
	}
	int a = removeDuplicates(arr);
	System.out.print("Array without the duplicate is: ");
	for(int j=0; j<a; j++)
	{
		System.out.print(arr[j] + " ");
	}
    }
}
