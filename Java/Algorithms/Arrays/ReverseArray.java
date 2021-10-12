
/**
 * Author:  ARUN BALAJI R
 * Date:    03 July 2021 (Saturday)
 */


import java.util.*;
public class ReverseArray{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int n;
		n=sc.nextInt();
		int ar[]=new int[n];
	    System.out.println("Enter array elements");
		for(int i=0;i<n;i++){
			ar[i]=sc.nextInt();
		}
		System.out.println("The reversed array is:");
		for(int i=(n-1);i>=0;i--){
			System.out.println(ar[i]+" ");
		}
		
	}
}