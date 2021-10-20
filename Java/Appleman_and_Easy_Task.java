import java.util.*;
public class Appleman_and_Easy_Task
{
    public static void main(String arg[])
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int count = 0;
        char num[][] = new char[n][n];
        for(int i = 0; i < n; i++)
        {
            String s = sc.next();
            for(int j = 0; j < n; j++)
            {
                num[i][j] = s.charAt(j);
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                count = 0;
                try
                {
                    if(num[i-1][j] == 'o')
                    {
                        count++;
                    }
                }
                catch(Exception e)
                {}
                try
                {
                    if(num[i][j+1] == 'o')
                    {
                        count++;
                    }
                }
                catch(Exception e)
                {}
                try
                {
                    if(num[i+1][j] == 'o')
                    {
                        count++;
                    }
                }
                catch(Exception e)
                {}
                try
                {
                    if(num[i][j-1] == 'o')
                    {
                        count++;
                    }
                }
                catch(Exception e)
                {}
                if(count % 2 != 0)
                {
                    System.out.println("NO");
                    System.exit(0);
                }
            }
        }
        System.out.println("YES");
        sc.close();
    }
}