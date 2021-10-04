package array;

public class Stocks {

	public static void main(String[] args) {
		int arr[] = {1,4,8,12,3};
		int n=arr.length;
		System.out.println("Array :");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
		int res = maxProfit(arr,0,n-1);
		System.out.println("\nMax Profit : "+res);
		System.out.println("..............");
		System.out.println("Max Profit : "+eff_maxProfit(arr));
	}
	static int maxProfit(int arr[],int start,int end) {  
		int maxProfit =0;
		if(start >= end) return 0;
		for (int i = start; i < end; i++) {
			for (int j = i+1; j <=end; j++) {
				if(arr[i]<arr[j]) {
					int profit= arr[j]-arr[i] 
						+	maxProfit(arr,start,i-1)
						+	maxProfit(arr,j+1,end);
					maxProfit = Math.max(profit, maxProfit);
				}
			}
		}
		return maxProfit;
	}
	
	static int eff_maxProfit(int arr[]) {
		int maxProfit =0;
		for (int i = 0; i < arr.length-1; i++) {
			if(arr[i]<arr[i+1])
				maxProfit += arr[i+1]-arr[i];
		}
		return maxProfit;
	}
}
