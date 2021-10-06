
/**
 * Author:  ARUN BALAJI R
 * Date:    11 August 2021 (Wednesday)
 */



import java.util.*;
public class ThreeEqualSum{

	public static boolean checkThreeEqualSum(int[] arr,int n){
		//computing sum of array
		int sum = 0;
		int splitCount = 0;
		for(int i=0;i<n;i++)	sum+=arr[i];

		//computing equal dividend
		int div = sum/3;

		//computing prefix sum
		int a[] = new int[n];
		a[0]=arr[0];
		if(a[0]%div==0) splitCount++;
		for(int i=1;i<n;i++){
			a[i]+=a[i-1]+arr[i];
			if(a[i]%div==0)
				splitCount++;
		}
		
		return splitCount==3;
	}

	public static void main(String args[]){
		int arr[] = {2,2,2};
		System.out.println(checkThreeEqualSum(arr,arr.length));
	}
}