import java.util.*;
public class Array
{
    public static void main(String arg[])
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList <Integer> neg = new ArrayList <Integer>();
        ArrayList <Integer> pos = new ArrayList <Integer>();
        ArrayList <Integer> zero = new ArrayList <Integer>();
        for(int i = 0; i < n; i++)
        {
            int temp = sc.nextInt();
            if(temp < 0)
            {
                neg.add(temp);
            }
            else if(temp == 0)
            {
                zero.add(temp);
            }
            else
            {
                pos.add(temp);
            }
        }
        if(pos.size() == 0)
        {
            pos.add(neg.remove(0));
            pos.add(neg.remove(0));
        }
        if(neg.size() % 2 == 0)
        {
            zero.add(neg.remove(0));
        }
        System.out.print(neg.size() + " ");
        for(int x : neg)
        {
            System.out.print(x + " ");
        }
        System.out.println();
        System.out.print(pos.size() + " ");
        for(int x : pos)
        {
            System.out.print(x + " ");
        }
        System.out.println();
        System.out.print(zero.size() + " ");
        for(int x : zero)
        {
            System.out.println(x + " ");
        }
        sc.close();
    }   
}