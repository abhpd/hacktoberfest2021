import java.util.*;
class insertionsort
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter number of numbers:");
        int n=sc.nextInt();
        String s[]=new String [n],x;
        int j;
        for(int i=0;i<n;i++)
        {
            s[i]=sc.nextLine();
        }
        for(int i=0;i<n;i++)
        {
            x=s[i];
            for( j=i-1;j>=0&& x.compareTo(s[j+1])>0;j--)
            {
            s[j+1]=s[j];
            s[j+1]=x;
        }
        }
        System.out.println("output");
        for(int i=0;i<n;i++)
        {
        System.out.println(s[i]);
    }
}
}
