 import java.util.*;
 public class WordCounter
 {
     public static void main(String[] args) 
     {  
         int count=0;  // Word Counter for String
         Scanner ob=new Scanner(System.in); // A standard input stream
         System.out.print("Enter a String : ");
         String s = ob.nextLine(); // Accepts the String
         char[] ch = new char[s.length()]; // Create an array to store String characters
         for(int i=0; i<s.length(); i++)  
         {  
             ch[i]= s.charAt(i); //Stores the String characters one by one
             if( ((i>0) && (ch[i]!=' ') && (ch[i-1]==' ')) || ((ch[0]!=' ') && (i==0)) )  
                 count++;  
         }  
         System.out.println("Number of Word(s) : " + count);   
     }  
 }  
 /* 
	Problem Statement - Write a Program to find the Number of Words in a String
 	
	Time Complexity = O(n)

 	Output :- 
 	Enter a String : Hello, I am under the water, please help me.
 	Number of Word(s) : 9
 */