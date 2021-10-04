package array;

import java.util.Scanner;

public class DeleteElement {

    public static void main(String []args){
        System.out.println("Array: ");
        int arr[] = {1,2,3,4,5,6,7},n;
        n = arr.length;
        printArr(arr, n);
        
        System.out.println("\nEnter element to be deleted : ");
        try (Scanner sc = new Scanner(System.in)) {
			int ele = sc.nextInt();
 
			int z = delElement(arr, ele);
			if (n == z)   	System.out.println("ELement not in array");
				System.out.println("Array after deletion : ");
				printArr(arr, z);
		}
        }
     
        static int delElement(int arr[], int ele)
        {   int n= arr.length, i=0;
            for(i=0;i<n;i++)
                {   if(ele == arr[i])                
                		break;
                }
            if (i == n) return n;
            
            for(i=0; i<n-1; i++) 
                arr[i] = arr[i+1];
            return (n-1);
        }
        
        static void printArr(int arr[], int n) {
        	for(int i=0;i<n;i++)
                System.out.print(arr[i]+" ");
        }
}
