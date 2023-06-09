// C++ implementation of Shell Sort
#include  <iostream>
using namespace std;
 
// Function to sort array using shellSort 
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        /* Do a gapped insertion sort for this gap size.
        The first gap elements a[0..gap-1] are already in gapped order
        keep adding one more element until the entire array is
        gap sorted */ 
        for (int i = gap; i < n; i += 1)
        {
            /*add a[i] to the elements that have been gap sorted
            save a[i] in temp and make a hole at position i */
            int temp = arr[i];
 
            /*shift earlier gap-sorted elements up until the correct
            location for a[i] is found*/
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}
 
void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout<<endl;
}
 
int main()
{
    int n;
    cout<<"Enter number of elements in array\n";
    cin>>n;

    int arr[n], i;
    cout<<"Enter elements of array\n";
    for(i=0;i<n;i++)
    {
      cin>>arr[i];
    }
 
    cout << "Array before sorting: \n";
    printArray(arr, n);
 
    shellSort(arr, n);
 
    cout << "Array after sorting: \n";
    printArray(arr, n);
 
    return 0;
}