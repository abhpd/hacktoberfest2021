import java.util.*;
public class Anton_and_Letters
{
    public static void main(String arg[])
    {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        Set <Character> set = new HashSet <Character>();
        for(int i = 1; i < str.length()-1; i += 3)
        {
            set.add(str.charAt(i));
        }
        System.out.print(set.size());
        sc.close();
    }   
}