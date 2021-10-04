import java.util.*;

public class Main{

public static void main(String[] args) {
  // write your code here  
  Scanner scn = new Scanner(System.in);
  int n = scn.nextInt();
  int k = 2;
  while(n/k != 0){
      if(n%k==0){
          System.out.print(k + " ");
          n = n/k;
      }else{
          k++;
      }
      
  }
 }
}