#include <bits/stdc++.h>
using namespace std;

//custom comparator function
 static bool compare(int a,int b){
        int count1=0,count2=0;
        //counting bits af a,b
        while(a){
            count1+=a&1;
            a>>=1;
        }
        while(b){
            count2+=b&1;
            b>>=1;
        }
        return count1>count2;
    }
    void sortBySetBitCount(int arr[], int n)
    {//stable sorting the array
        stable_sort(arr,arr+n,compare);
    }


//Driver code
int main()
{
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        sortBySetBitCount(arr, n);
        //output of the array after sorting
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    
    return 0;
}