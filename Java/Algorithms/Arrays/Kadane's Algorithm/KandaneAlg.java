import java.util.Scanner;

public class KandaneAlg {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the size of array");
        int n=s.nextInt();
        int []a=new int[n];
        for(int i=0;i<n;i++){
            a[i]=s.nextInt();
        }
        s.close();
        System.out.println("Max sum of sub array is "+maxSubarraySum(a,n));
    }
    static long maxSubarraySum(int arr[], int n){
        long max=Integer.MIN_VALUE;
        long currsum=0;
        for(int i=0;i<n;i++){
            currsum=currsum+arr[i];
            if(currsum>max){
                max=currsum;
            }
            if(currsum<0){
                currsum=0;
            }
        }
        return max;
    }
}
