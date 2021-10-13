import java.io.*;
import java.util.*;

public class dynamicProgramming {

    public static void main(String[] args) throws Exception {
   Scanner scn=new Scanner(System.in);
   
   int n=scn.nextInt();
   int arr[]=new int[n];
   for(int i=0;i<n;i++){
       arr[i]=scn.nextInt();
   }
   int cap=scn.nextInt();
   int dp[]=new int[cap+1];
   dp[0]=1;
   for(int coin:arr){
       
       for(int j=coin;j<=cap;j++){
           dp[j]+=dp[j-coin];
       }
   }
   
   System.out.println(dp[cap]);
    }
}