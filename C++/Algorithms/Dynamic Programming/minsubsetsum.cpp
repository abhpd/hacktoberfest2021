//We are given an array of non-negative integers, we need to  divide it into two subsets S1 and S2 such that the absolute difference between the sums of integers of two sets S1 and S2 is minimum and return this minimum difference

/*The basic idea to solve is:
  array has two subsets:
   The sum of numbers in subset1 is say S1
  The sum of numbers in subset2 is say S2
  S1+S2=sum of array elments --> S1 and S2 will be lesser than sum
  let S2>S1 for *****S2-S1=?******
  So S1 will be in between [0 to (sum/2)]; 
  S2-S1-->(Sum-S1)-S1--->Sum-(2*S1)
  Ans=minimum of Sum-(2*S1) -->for this to be minimum S1 should me maximum and less than equal to (sum/2);
*/
#include <bits/stdc++.h>
using namespace std;

int minDifference(int arr[], int n)
{
      int sum=0; //sum of array elenents
      for(int i=0;i<n;i++)
      sum+=arr[i];

     //The state of  dp[i][j] is if first i elements of array are present and if any subset of these i elements can have sum as j then dp[i][j]=1 otherwise dp[i][j]=0;
      bool dp[n+1][(sum/2)+1]; 

      //Initialising dp array
      for(int i=1;i<=(sum/2);i++)
      dp[0][i]=0; //as zero elements are present so we can't have desired sum
      for(int i=0;i<=n;i++)
      dp[i][0]=1;  //we can always have sum as zero as null subset exists

      for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=(sum/2);j++)
        {
            if(arr[i-1]>j)  //arr[i-1] can't contribute in sum j
            dp[i][j]=dp[i-1][j];
            else //arr[i-1] can contribute 
            {
                /*if this sum is already achieved with i-1 elements OR j-arr[i-1] had been achieved then j can be possible  sum   otherwise not*/
                 dp[i][j]= ((dp[i-1][j])|| (dp[i-1][j-arr[i-1]])); 
            }
        }
    }
    int s1; 
    for(int i=(sum/2);i>=0;i--)
    {
        if(dp[n][i]==1)
       {
            s1=i; //max S1 existing
            break;
       }
    }
    int s2=sum-s1;

    return abs(s2-s1);
}

signed main()
{
     int size;
     cin>>size;    //input of size of array
     int arr[size];

     for(int i=0;i<size;i++)
     cin>>arr[i];     //input of array elements

     int ans=minDifference(arr,size);
     cout<<ans;
    
}