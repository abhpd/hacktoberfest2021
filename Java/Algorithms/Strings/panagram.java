import java.util.Scanner;
public class MainStr1 
{
public static void main(String[] args)
 {
	Scanner sc= new Scanner(System.in);
	System.out.println("Enter the sentence: ");
	String st=sc.nextLine();
	   boolean rs=isPangram(st);
	   if(rs==true)
		   System.out.println("String is Panagram");
	   else
		   System.out.println("String is not a Panagram");
 }
private static boolean isPangram(String st) 
 {
	if(st.length()<26)
		return false;
	int count[]=new int[26];
	for(int i=0;i<st.length();i++)
	{
		char ch=st.charAt(i);
		if(ch>=65&&ch<=90)
			count[ch-65]++;
		else if(ch>=97&&ch<=122)
			count[ch-97]++;
	}
	  for(int i=0;i<26;i++)
	  {
		  if(count[i]==0)
			  return false;
	  }
	return true;
 }
}
           
           
        
