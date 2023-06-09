import java.util.*;
 public class Palindrome{  
 public static void main(String args[]){  
  int r,sum=0,temp;
  System.out.println("enter a number");
  Scanner in = new Scanner(System.in);    
    int n=in.nextInt();
  
  temp=n;    
  while(n>0){    
   r=n%10;  //getting remainder  
   sum=(sum*10)+r;    
   n=n/10;    
  }    
  if(temp==sum)    
   System.out.println(temp+"  is a palindrome number ");    
  else    
   System.out.println(temp+"  is not a not palindrome");    
}  
}
