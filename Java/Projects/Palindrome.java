/*
To check if a number or word is a palindrome
Bahukhandi93

*/

import java.util.Scanner;

public class palindrome {

    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        sc.useDelimiter("\n");

        System.out.println("\fEnter the word you wish to check for palindrome:"); 
        String word = sc.next();  //inputting the original word
        int n=word.length();  //length of the word

        String revWord= "";  //decalring a variable to store the reverse of the original word
        for(int i=n-1;i>=0;i--)  //creating the reverse of the original word
        {
            char ch=word.charAt(i);
            revWord += ch;
        }

        if(revWord.equalsIgnoreCase(word)) //to check if the reverse of the word is the same as the original
            System.out.print(word+" is a palindrome! :)");
        else
            System.out.print(word+" is NOT a palindrome");
    }
}
