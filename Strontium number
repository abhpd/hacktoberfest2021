import java.util.*;  
public class StrontioNumberExample1   
{  
public static void main(String args[])   
{  
Scanner sc=new Scanner(System.in);  
System.out.print("Enter the number: ");  
//reading an integer from the user  
int num=sc.nextInt();  
int n=num;  
//first, we have multiplied a number by 2  
//the resultant is divided by 1000 that gives the remainder and removes the first digit  
//at last, the resultant is divided by 10 that removes the last digit   
//therefore, we get a two-digit number that are mean digits of the given number  
num=(num*2%1000)/10;  
//divide the two-digit number (that we get from the above) by 10 and find the remainder  
//compares the remainder and quotient   
if(num%10==num/10)  
//if equal, prints strontio number  
System.out.println(n+ " is a strontio number.");  
else  
//prints if not a strontio number  
System.out.println(n+ " is not a strontio number.");  
}  
}  
