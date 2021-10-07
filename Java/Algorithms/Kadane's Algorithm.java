import java.util.*;

public class Main {
    static int maxSubArraySum(int arr[]) {

        int length = arr.length;
        int max_away = 0, max_ending_here = 0;
 

        for (int i = 0; i < length; i++) {
            max_ending_here = max_ending_here + arr[i];
            if (max_away < max_ending_here)
                max_away = max_ending_here;
            if (max_ending_here < 0)
                max_ending_here = 0;
            
        }

        return max_away;
    }
 
    public static void main(String[] arg) {
    Scanner Sc=new Scanner(System.in);
    int size=Sc.nextInt();
        int[] arr=new int[size];
        for(int i=0;i<size;i++) 
	    {
	      arr[i]=Sc.nextInt();
	    }
        System.out.println("Maximum sum is " +
                maxSubArraySum(arr));
 
 
    }
}
