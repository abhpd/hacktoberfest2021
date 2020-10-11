import java.io.*;
import java.util.*;

class sort{
    public void mergeSort(int[] arr,int left,int right){
        if(left<right){
            int mid = (left+right)/2;
        
            mergeSort(arr,left,mid);
            mergeSort(arr,mid+1,right);
        
            merge(arr,left,mid,right);
        }
    }
    public void merge(int[] arr,int left,int mid,int right){
        int n1 = mid-left+1;
        int n2 = right-mid;
        int[] l = new int[n1];
        int[] r = new int[n2];
        int i=0,j=0;
        
        for(;i<n1;i++)
            l[i] = arr[left+i];
        for(;j<n2;j++)
            r[j] = arr[mid+j+1];
        
        i=0;j=0;
        int k=left;
        
        while(i != n1 && j != n2){
            if(l[i]<=r[j]){
                arr[k] = l[i];
                i++;
            } 
            else{
                arr[k] = r[j];
                j++;
            }
            k++;
        }
        while(i != n1){
            arr[k] = l[i];
            i++;
            k++;
        }
        while(j != n2){
            arr[k] = r[j];
            j++;
            k++;
        }
    }
}
class mergeSorting {
	public static void main (String[] args){
		int[] arr = {2,4,7,2,9,50,99,3,6,3,7,01};
		int n = arr.length;
		sort ms = new sort();
		System.out.println(Arrays.toString(arr));
		ms.mergeSort(arr,0,n-1);
		System.out.println(Arrays.toString(arr));
	}
}