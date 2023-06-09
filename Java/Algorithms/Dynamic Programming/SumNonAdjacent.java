import java.util.*;
public class SumNonAdjacent {
 	public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<arr.length;i++){
            arr[i]=sc.nextInt();
        }
        int inc=arr[0];
        int exc=0;
        for(int i=1;i<arr.length;i++){
            int newInc=exc+arr[i];
            int newExc=Math.max(inc,exc);
            
            inc=newInc;
            exc=newExc;
        }
        System.out.println(Math.max(inc,exc));
    }
}
