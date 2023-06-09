#include<iostream>
using namespace std;
int main()
{
int n, i, j, temp, gap;
cout<<"Enter the number of elements:\n";
cin >> n;
int arr[n];
cout<<"Enter the elements:\n";
for(i = 0; i < n; i++)
{
cin >> arr[i];
}
for (gap = n/2; gap > 0; gap = gap / 2) 
{ 

// Do a gapped insertion sort 
// The first gap elements arr[0..gap-1] are already in gapped order 
// keep adding one more element until the entire array is gap sorted 
for (i = gap; i < n; i = i + 1) 
{ 

// add arr[i] to the elements that have been gap sorted 
// save arr[i] in temp and make a empty space at index i 
int temp = arr[i]; 
// shift earlier gap-sorted elements up until the correct location for arr[i] is found 
for (j = i; j >= gap && arr[j - gap] > temp; j = j - gap) 
arr[j] = arr[j - gap]; 

// put temp (the original arr[i]) in its correct position
arr[j] = temp; 
} 
} 
cout<<"Sorted elemets:\n";
for(i = 0; i < n; i++)
{
cout << arr[i] << " ";
}
}