#include <bits/stdc++.h>
using namespace std;

//function to find the kth element out of arrays
int kthElement(int arr1[], int arr2[], int n, int m, int k){
        int i=n-1,j=0;
        //merge sort without using extra array
        while(i>=0&&j<m){
            if(arr1[i]>=arr2[j]){
                swap(arr1[i],arr2[j]);
                i--;
                j++;
            }
            else
              break;
              
        }
        //sorting the two arrays
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
        //if k lies in 1st array or 2nd one
        if(k<=n)
           return arr1[k-1];
        else
           return arr2[k-n-1];
    }

 
// Driver code
int main()
{
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
        //taking input of the elements of arrays
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
         //printing the kth element
        cout << kthElement(arr1, arr2, n, m, k)<<endl;
    return 0;
}  