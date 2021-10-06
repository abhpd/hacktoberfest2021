import java.util.*;

class BinSearchTwoDArray{
	// Time Complexity : O(N)
	public static int[] binSortTwoDArray(int[][] arr,int target){
		int row = 0;
		int column = arr.length-1;

		while(row < arr.length && column >= 0){
			if(target==arr[row][column])
				return new int[]{row,column};
			if(target>arr[row][column])
				row++;
			else
				column--;
		}
		return new int[]{-1,-1};
	}

	public static void main(String args[]){

		//row column matrix
		int[][] arr = {
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,16},
		};
		System.out.println(Arrays.toString(binSortTwoDArray(arr,15)));
	}
}