
/**
 * Author:  ARUN BALAJI R
 * Date:    09 August 2021 (Monday)
 */


import java.util.*;
public class CountDistinctElementWindow{

	static void countDistinctElement(int[] arr,int n,int k){
		List list = new ArrayList();
		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();

		//firstt k elements
		for(int i=0;i<k;i++){
			map.put(arr[i],map.getOrDefault(arr[i],0)+1);
		}
		list.add(map.size());

		//next elements
		for(int i=1;i<=n-k;i++){
			decElementCount(map,arr[i-1]);
			map.put(arr[i+k-1],map.getOrDefault(arr[i+k-1],0)+1);
			list.add(map.size());
		}
		System.out.println(list);
	}

	//remove or decrement count of element
	private static void decElementCount(Map<Integer,Integer> map,int e){
		Integer count = map.get(e);
		if(count !=null && count > 1){
			map.put(e,count-1);
		}else{
			map.remove(e);
		}
	}



	//DRIVER CODDE
	public static void main(String args[]){
		int[] arr = {4,1,1};
		countDistinctElement(arr,arr.length,2);
		

	
	}
}