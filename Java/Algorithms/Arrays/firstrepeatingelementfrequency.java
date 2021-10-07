
/**
 * Author:  Sneha Mehta
 * Date:    07 October 2021 (Thursday)
 */


import java.util.*;
public class FirstRepeatingElement
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of elements of your array");
		int m= sc.nextInt();
		int arr[] = new int[m];
		System.out.println("Enter the elements of your array");
		for(int i=0;i<arr.length-1;i++)
		{
			arr[i]=sc.nextInt();
		}
		int n=0;
		for(int i=0;i<arr.length-1;i++)
		{
			for(int j=i;j<arr.length-1;j++)
			{
				if(arr[i]==arr[j])
				n++;
			}
			if(n>1)
			System.out.println("The first repeating element is "+arr[i]);
			System.out.println(arr[i]+" occurs "+n+" times in the entered array");
			break;
		}
	}
}