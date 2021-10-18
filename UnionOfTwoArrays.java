import java.util.*;
import java.io.*;
class UnionOfTwoArrays
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            int m = sc.nextInt();
            
            int arr[] = new int[n];
            int brr[] = new int[m];
            
            HashSet<Integer> s = new HashSet<>();
            
            // for each element in first array
            // add the elements to the set
            for(int i = 0; i < n; i++)
            {
                int val = sc.nextInt();
                arr[i] = val;
                s.add(arr[i]);
            }
            
            // for each element in the seconf array
            // add the elements to the set
            // as set contains duplicate elements
            for(int i = 0; i < m; i++)
            {
                int val = sc.nextInt();
                brr[i] = val;
                s.add(brr[i]);
            }
            System.out.println(s.size());
        }
    }
}