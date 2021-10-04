// Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.
// Example 1:

// Input:
// n = 6, X = 13
// arr[] = [1 4 45 6 10 8]
// Output:
// 1
// Explanation:
// The triplet {1, 4, 8} in the array sums up to 13.



import java.util.*;
import java.io.*;
import java.lang.*;

class Main
{
    public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
		while(t-->0){
		    String inputLine[] = br.readLine().trim().split(" ");
		    int n = Integer.parseInt(inputLine[0]);
		    int X = Integer.parseInt(inputLine[1]);
		    int A[] = new int[n];
		    inputLine = br.readLine().trim().split(" ");
		    for(int i=0; i<n; i++){
		        A[i] = Integer.parseInt(inputLine[i]);
		    }
		    Solution ob=new Solution();
		    boolean ans = ob.find3Numbers(A, n, X);
		    System.out.println(ans?1:0);
		}
	}
}

class Solution
{
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    public static boolean find3Numbers(int a[], int n, int x) { 
    
       // Your code Here
       int i=0,j=1,k=n-1,sum;
       boolean ans=false;
       Arrays.sort(a);
       while(i<n-2){
           j=i+1;
           k=n-1;
       while(j<k){
           
           sum=a[i]+a[j]+a[k];
           //System.out.println(sum);
           if(sum<x)
           j++;
           else if(sum>x)
           k--;
           else if(sum==x){
           ans=true;
           break;}
       }
        i++;   
       }
       return ans;
    
    }
}
