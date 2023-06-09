import java.util.*;
public class Get_Common_Elements
{
public static void main(String[] args)
{
    Scanner sc = new Scanner(System.in);
    HashMap<Integer,Integer> mp = new HashMap<>();
    int n1 = sc.nextInt();
    for(int i=0;i<n1;i++)
    {
        int val = sc.nextInt();
        mp.put(val,mp.getOrDefault(val,0)+1);
    }
    int n2 = sc.nextInt();
    for(int i = 0;i<n2;i++)
    {
        int val = sc.nextInt();
        if(mp.containsKey(val) && mp.get(val)!=-1)
        {
            mp.put(val,-1);
            System.out.println(val);
        }
    }
 }

}