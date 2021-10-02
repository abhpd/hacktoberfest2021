#include<bits/stdc++.h>
using namespace std;

/* Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

Question link:  https://leetcode.com/problems/unique-paths-ii/ 
*/


    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m= g.size();
        int n=g[0].size();
        if(m==1 && n==1 && g[0][0]==0)return 1;
        if(m==1 && n==1 && g[0][0]==1)return 0;
        if(g[0][0]==1)return 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1)g[i][j]=-1;
            }
        }
        for(int i=1;i<n;i++){
             if(g[0][i]!=-1){
            if(g[0][i-1]==-1)g[0][i]=-1;
            else g[0][i]=1;
             }
        }
        for(int i=1;i<m;i++){
            if(g[i][0]!=-1){
            if(g[i-1][0]==-1)g[i][0]=-1;
            else g[i][0]=1;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(g[i][j]!=-1){
                if(g[i-1][j]==-1 && g[i][j-1]==-1)g[i][j]=-1;
                else if (g[i-1][j]==-1)g[i][j]=g[i][j-1];
                else if (g[i][j-1]==-1)g[i][j]=g[i-1][j];
                else g[i][j]=g[i-1][j]+g[i][j-1];
                }
            }
        }
        return max(g[m-1][n-1],0);
    }

