import java.util.*;
import java.io.*;


class Main{

	public static void binSearchSmallest(int a[], int n){
		//5 1 2 3 4
		int left = 0, right = n-1;//left = 0, right = 1
		while(left <= right){
			int mid = left + (right - left) / 2; //mid = 0
			if(a[left] < a[right]){
				System.out.println(a[left]);
				break;
			}
			if(a[left] <= a[mid]){
				left = mid + 1; //left = 1
			}
			else{
				right = mid; //right = 1
			}
			if(a[left] == a[right]){
				System.out.println(a[left]);// 1
				break;
			}
		}
	}
	public static void main (String[] args) {
			Scanner s = new Scanner(System.in);
			int t = s.nextInt();
			for(int j=0;j<t;j++){
				int n = s.nextInt();
				int a[] = new int[n];
				for(int i=0;i<n;i++){
					a[i] = s.nextInt();
				}
				binSearchSmallest(a, n);
			}
	}
}
