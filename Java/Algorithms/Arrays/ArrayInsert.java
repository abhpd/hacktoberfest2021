
/**
 * Author:  Aliza Dixit
 * Date:    16/09/2021
 */


import java.util.*;
public class ArrayInsert{
	public static void main(String args[]){
		Solution s = new Solution();
		int arr[] = new int[5];
		for(int i=0;i<arr.size();i++){
		 int n = kb.nextInt(s.insertAtEnd(arr,i));
		}
		
		s.printArray(arr);

		s.insertAtStart(arr,2);
		
		s.printArray(arr);
		s.insertAtPos(arr,1,20);
		s.printArray(arr);
		
	}
}

class Solution{
	int count = 0;
	//insert array element at end
	void insertAtEnd(int arr[],int val){
		arr[count++] = val;
	}

	//insert array element at start

	void insertAtStart(int arr[],int val){
		for(int i=count;i>0;i--){
			arr[i]=arr[i-1];
		}
		arr[0] = val;
	}

	//insert element at given position
	void insertAtPos(int arr[],int pos,int val){
		for(int i=count;i>pos;i--){
			arr[i] = arr[i-1];
		}
		arr[pos]= val;
	}


	void printArray(int arr[]){
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" ");
		System.out.println();
	}




}