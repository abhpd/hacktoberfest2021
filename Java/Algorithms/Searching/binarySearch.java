import java.io.*;

class search{
    public int binarySearch(int[] arr,int x,int left,int right){
        while(left<=right){
            int mid = (right+left)/2;
            if(arr[mid] == x)
                return mid;
            else if(arr[mid] < x)
                return binarySearch(arr,x,mid+1,right);
            else
                return binarySearch(arr,x,left,mid-1);
        }
        return -1;
    }
}
class binarySearch{
	public static void main (String[] args) {
		int[] arr = {1,3,6,7,9,50,99,1000,1563,2000};
		int n = arr.length, x = 1000;
		search bs = new search();
		System.out.println("Element "+x+" is at "+bs.binarySearch(arr,x,0,n-1)+" position");
	}
}