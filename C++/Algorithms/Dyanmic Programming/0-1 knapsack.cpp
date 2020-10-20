
/* Given two integer arrays val[0.....n-1] and wt[0.....n-1] which represent values and weights of n items respectively. 
Also given an integer W representing the Knapsack's capacity . find the maximum value subset of val[] such that
sum of the weights of this subset is smaller than or equal to W */
  
//solution
  
#include <bits/stdc++.h> 
using namespace std; 

int knapSack(int W, int wt[], int val[], int n) 
{ 
  
   int i, w; 
    int K[n + 1][W + 1]; 
    for (i = 0; i <= n; i++) { 
      for (w = 0; w <= W; w++) { 
         if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max( val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
  
    return K[n][W]; 
} 
  
int main() 
{ 
    int n,i;
    cin>>n;
    int val[n];
    int wt[n];
    for(i=0;i<n;i++){
        cin>>val[i];
    }
    
    for(i=0;i<n;i++){
        cin>>wt[i];
    }
    int W;
    cin>>W;
    
    cout << knapSack(W, wt, val, n); 
    return 0; 
} 
