import java.io.*;
import java.util.*;

class linearSearch {
    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        String[] str2 = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);
        int[] arr = new int[n];
        int i = 0;
        for(i=0;i<n;i++)
            arr[i] = Integer.parseInt(str2[i]);
        for(i= n-1;i>=0;i--)
            if(arr[i] == m){
                System.out.println(i+1);
                break;
            }
        if(i == n)
            System.out.println(-1);

    }
}