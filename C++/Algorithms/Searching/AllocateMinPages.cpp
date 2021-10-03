#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
    bool isAllocate(int barr,int A[],int N,int M){
        int alctdstd=0,pages=0;
        for(int i=0;i<N;i++){
            
            if(A[i]+pages>barr){
                pages=A[i];
                alctdstd+=1;
                if(pages>barr)
                     return false;
            }
            else
               pages+=A[i];
        }
        if(alctdstd<M)
        return true;
        else
        return false;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
       int low=INT_MAX,high=0;
       for(int i=0;i<N;i++){
           low=min(low,A[i]);
           high+=A[i];
       }
       int res=-1;
       while(low<=high){
           int mid=(low+high)>>1;
           if(isAllocate(mid,A,N,M)){
               res=mid;
               high=mid-1;
           }
           else
             low=mid+1;
       }
       return res;
    }
};

// Driver Code 

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
