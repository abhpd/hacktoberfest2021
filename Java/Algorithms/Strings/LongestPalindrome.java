
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static int ispalindrome(String s)
    {
        String reverse = new StringBuffer(s).reverse().toString();
        if(s.equals(reverse))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		{
		    while(t-->0)
		    {
		        String str=sc.next();
		        String ans="";
		        int max=0;
		        for(int i=0;i<str.length();i++)
		        {
		            for(int j=str.length();j>i;j--)
		            {
		                String pal = str.substring(i,j);
		                if(ispalindrome(pal)==1)
		                {
		                    if((j-i)>max)
		                    {
		                        ans=pal;
		                        max=j-i;
		                    }
		                }
		            }
		        }
		        System.out.println(ans);
		    }
		}
	}
}
