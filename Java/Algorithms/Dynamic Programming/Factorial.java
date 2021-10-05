import java.util.*;

public class Factorial
{
  static ArrayList<Integer> arr;
  static int fact(int n)
  {
    arr = new ArrayList<>();
    arr.add(1);
    for(int i=1; i<=n; i++)
    {
      arr.add(i*arr.get(i-1));
    }

    return arr.get(n);
  }

  public static void main(String args[])
  {
    Scanner k = new Scanner(System.in);
    System.out.print("Enter a number: ");
    int n = k.nextInt();
    System.out.println("The Factorial of " + n + " is = " + fact(n));

  }
}
