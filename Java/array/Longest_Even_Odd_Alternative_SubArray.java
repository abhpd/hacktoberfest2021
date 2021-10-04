package array;

public class Longest_Even_Odd_Alternative_SubArray {

	public static void main(String[] args) {
		int arr[] = {1,2,2};
		System.out.println("Array :");
		for (int i = 0; i < arr.length; i++) 
			System.out.print(arr[i]+" ");
		int res = alternateOddEven(arr);
		System.out.println("\nLongest Even Odd Alternative Sub Array : "+res);
		int eff= eff_gfgks(arr);
		System.out.println("Another Solution : "+eff);
	}
	static int alternateOddEven(int arr[]) {
		int max=2,res=1;
		for (int i = 0; i < arr.length-2; i++) {
			if ( ((arr[i]%2 == 0) && (arr[i+2]%2 == 0) &&(arr[i+1]%2 == 1)) // E O E
					|| ((arr[i]%2 != 0) && (arr[i+2]%2 != 0) && (arr[i+1]%2 == 0))
				) 
			{	max++;
				res = Math.max(res, max);
			}
			else
				max=2;
		}
		return res;
	}

	static int eff_gfgks(int arr[]) {
		int res=1,sum=1;
		for (int i = 1; i < arr.length; i++) {
			if( (arr[i-1]%2 == 0 && arr[i]%2 == 1) || 
					(arr[i-1]%2 ==1 && arr[i]%2==0)	) {
				sum++;
				res=Math.max(res, sum);
			}
			else sum=1;			
		}
		return res;
	}
}
