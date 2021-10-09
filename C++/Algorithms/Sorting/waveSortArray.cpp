// Code In C++ Lnaguage
#include<bits/stdc++.h>
using namespace std;

// created a class WaveSort
class WaveSort{
    public:
        // class method convertToWaveForm
        void convertToWaveForm(int *arr, int n){
            // swapping the positions of arr[i] & arr[i+1] by incrementing loop after 2 steps
            for(int i=0; i<n-1; i+=2)
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
};

int main()
{
    int n=7;
    int a[n]={100, 2, 1, 6, 19, 27, 5}; 
    
    // sorting the entire array before performing wave sort
    sort(a,a+n);
        
    // created an object of class WaveSort and calling its method convertToWaveForm to perform wave sort on the sorted array
    WaveSort ob;
    ob.convertToWaveForm(a, n);

    // displaying the final array
    cout<<"Array after performing wave sort would be -->"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" "; 
    cout<<endl;
    return 0;
}