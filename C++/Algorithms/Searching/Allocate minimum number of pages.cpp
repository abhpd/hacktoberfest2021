/*You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate contagious books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages.
Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations and print this minimum value. 

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding)


Sample Input and Output with Explanation:

Input:
N = 4
A[] = {12,34,67,90}
M = 2

Output:
113

Explanation: 
Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90}  Maximum Pages =113
Therefore, the minimum of these cases is 113, which is selected as the output.
*/
#include<bits/stdc++.h>
using namespace std;

bool valid(int A[],int N,int M,int mid){           
        int student=1;
        int s=0;
        for(int i=0;i<N;i++){
            s=s+A[i];
            if(s>mid)
            {
                student++;
                s=A[i];
            }
            
        }
        if(student>M)
        return false;
        return true;
        
    }
    int findPages(int A[], int N, int M) 
    {
      
       int start=0;
       int end=0;
       start=*max_element(A,A+N);
       for(int i=0;i<N;i++)
       end=end+A[i];
       
       int ans=-1;
       while(start<=end){
           int mid=start+(end-start)/2;
           if(valid(A,N,M,mid)==true){
               ans=mid;
               end=mid-1;
           }
           else
           start=mid+1;
       }
       return ans;
    }

    int main(){
        int N;
        cin>>N;
        int v[N];
        for(int i=0;i<N;i++)
            cin>>v[i];
        int M;
        cin>>M;
        int ans=findPages(v,N,M);
        cout<<ans<<"\n";
    }