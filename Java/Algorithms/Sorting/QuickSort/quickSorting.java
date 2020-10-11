import java.io.*;
import java.util.*;

class sort{
   void QuickSort(int[] arr,int left,int right){
       if(left<right){
            int pi = partition(arr,left,right);
       
            QuickSort(arr,left,pi-1);
            QuickSort(arr,pi+1,right);
       }
   }
   int partition(int[] arr,int left,int right){
       int key = arr[right];
       int i = left-1;
       int j=0;
       for(j=left;j<right;j++){
           if(key > arr[j]){
               i++;
               int temp = arr[j];
               arr[j] = arr[i];
               arr[i] = temp;
           }
        }
        int temp = arr[right];
        arr[right] = arr[i+1];
        arr[i+1] = temp;
        return i+1;
   }
}
class quickSorting {
	public static void main(String[] args){
		int[] arr = {2,4,7,2,9,50,99,3,6,3,7,01};
		int n = arr.length;
		sort qs = new sort();
		System.out.println(Arrays.toString(arr));
		qs.QuickSort(arr,0,n-1);
		System.out.println(Arrays.toString(arr));
	}
}