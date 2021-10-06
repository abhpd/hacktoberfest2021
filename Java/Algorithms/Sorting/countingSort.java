
import java.util.Scanner;

public class countingSort {
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=s.nextInt();

        int output[]=new int[n+1];
        // Find the largest element of the array
        int max=arr[0];
        for(int i=1;i<n;i++) {
            if(arr[i]>max)
            max = arr[i];
        }
        int[] count = new int[max + 1];
        for(int i=0;i<n;i++)
            count[arr[i]]++;

        for(int i=1;i<=max;i++)
            count[i]=count[i]
                    +count[i-1];

        for(int i=n-1;i>=0;i--)
        {
            output[count[arr[i]]-1]=arr[i];
            count[arr[i]]--;
        }
        for(int i=0;i<n;i++) {
            arr[i] = output[i];
            System.out.print(arr[i]+" ");
        }


    }
}
