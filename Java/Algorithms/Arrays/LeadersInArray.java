
/**
 * Author:  ARUN BALAJI R
 * Date:    07 July 2021 (Wednesday)
 */


import java.util.*;
public class LeadersInArray{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[]={7,10,4,10,6,5,2};
		// s.findLeaders(arr);
		System.out.println(s.findLeadersEff(arr));
	}
}

class Solution{

	//O(n2)
	public void findLeaders(int arr[]){
		int n = arr.length;
		for(int i=0;i<n;i++){
			boolean flag=false;
			for(int j=i+1;j<n;j++){
				if(arr[i]<=arr[j]){
					flag = true;
					break;
				}
			}
			if(flag == false)
    		{
    			System.out.print(arr[i]+" ");
    		}
		}

		

	}

	//O(n)
	ArrayList<Integer> findLeadersEff(int arr[]){
		
		ArrayList<Integer> leaders = new ArrayList<Integer>();
		int n=arr.length;
		int leader = arr[n-1];
		leaders.add(leader);
		for(int i=n-2;i>=0;i--){
			if(arr[i]>leader){
				leader=arr[i];
				leaders.add(leader);
			}
		}

		Collections.reverse(leaders);
		return leaders;
		

	}
}