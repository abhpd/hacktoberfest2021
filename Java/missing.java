// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.
// Example 1:

// Input:
// N = 2
// Arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and smallest positive missing number is 1.

import java.io.*;
import java.util.*;

class Find {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] str = br.readLine().split(" ");

            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(str[i]);
            }

            int[] ans = new Solve().findTwoElement(a, n);
            System.out.println(ans[0] + " " + ans[1]);
        }
    }
}// } Driver Code Ends


// User function Template for Java

class Solve {
    int[] findTwoElement(int arr[], int n) {
        // code here
        int[] b=new int[n+1];
        int[] r=new int[2];
        for(int i=0;i<n;i++){
            if(b[arr[i]]==1)
            r[0]=arr[i];
            else
            b[arr[i]]=1;
        }
        //System.out.println(Arrays.toString(b));
        for(int j=1;j<n+1;j++){
        if(b[j]==0)
        r[1]=j;
        }
        
        return r;
    }
}
