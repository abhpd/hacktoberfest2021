
/**
 * Author:  ARUN BALAJI R
 * Date:    16 July 2021 (Friday)
 */


import java.util.*;
public class StockBuyandSell{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = {1,5,3,1,2,8};
		System.out.println(s.maxProfit(arr,arr.length));
	}
}


class Solution{
	int maxProfit(int arr[],int n){  
		int profit= 0;	//profit = 0,maxprofit = 0;
		for(int i=1;i<n;i++){			//i=5
			if(arr[i]>arr[i-1]){		//8>2 true
				profit+=(arr[i]-arr[i-1]);
			}
		
		}
		return profit;
	}
}