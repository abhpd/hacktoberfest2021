import java.util.*;
public class mergeSortedArray{

     public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        
        System.out.println("enter size of first array: ");
        int m = sc.nextInt();
        System.out.println("enter size of second array: ");
        int n = sc.nextInt();
        
        int[] nums1 = new int[n+m];
        System.out.println("enter elements of first array : ");
        for(int i=0 ; i<m ; i++){
            nums1[i] = sc.nextInt();
        }
        
        
        int[] nums2 = new int[n];
        System.out.println("enter elements of second array : ");
        for(int i=0 ; i<n ; i++){
            nums2[i] = sc.nextInt();
        }
        sc.close();
        
        merge(nums1 , m , nums2 , n);
        System.out.println("The merged array is : ");
        for(int i=0 ; i<n+m ; i++){
            System.out.println(nums1[i]);
        }
        
        
     }
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        // three pointer approach 
        int pos = m + n - 1;
        while(m > 0 && n > 0){
            if(nums1[m - 1] > nums2[n - 1]){
                nums1[pos] = nums1[m - 1];
                m--;
            } else {
                nums1[pos] = nums2[n - 1];
                n--;
            }
            pos--;
        }
        
        while(n > 0){
            nums1[pos] = nums2[n - 1];
            n--;
            pos--;
        }
    }

}
