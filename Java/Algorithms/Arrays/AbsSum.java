import java.util.*;
import java.lang.Math;
public class AbsSum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	    Scanner input =new Scanner(System.in);
       
        
     
        	
        	   int n=input.nextInt();
               int sum=0;
               int arr[]=new int[n];
               for(int i=0;i<arr.length;i++){
                   arr[i]=input.nextInt();
                   arr[i]=Math.abs(arr[i]);
               }
                for(int i=0;i<arr.length;i++){
                  sum+=arr[i];
                                     
               }
               
                   System.out.print (Math.abs(sum)+" ");
                      	
         
      

	}

}
