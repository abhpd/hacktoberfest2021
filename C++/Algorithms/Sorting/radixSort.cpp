#include<iostream>
using namespace std;

//utility function to get max value in array
int getMax(int arr[], int n)
{
    int maxEle = arr[0];
    for(int i = 0; i < n; i++)
        maxEle = max(maxEle , arr[i]);
    
    return maxEle;
}

//a function to count sort array according to the digit represented by exp
void countSort(int arr[], int n, int exp)
{
    int output[n];      //output array
    int i , count[10] = {0};

    //store the count of occurences in count[]
    for(i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    //change count[i] so that count[i] now contains actual position of this digit in output[]
    for(i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    //build the output arrays
    for(i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    //copy the output array to arr[], so that arr[] now contains sorted numbers according to currect digit 
    for(i = 0; i < n; i++)
        arr[i] = output[i];
}
//the main function to sort arr[n] using radix sort 
void radixsort(int arr[], int n)
{
    //find max element to find number of digits
    int maxEle = getMax(arr, n);

    //do counting sort for every digit 
    //instead of passing digit number, exp is passed
    //exp is 10^i, where i is current digit number
    for(int exp = 1; maxEle / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

//utility function to print array
void print(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}
//driver code
int main()
{
    int n;
    cout<<"\nEnter Size - ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter Array Elements - \n";
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    //function call
    radixsort(arr, n);
    print(arr,n);
    
    return 0;
}