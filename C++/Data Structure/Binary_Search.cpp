//Binary Search->

#include <iostream>
using namespace std;
int main()
{
     int n,i, num, first, last, middle;
     cout<< "Enter the number of elements in array:\n";
     cin>>n;
     int arr[n];
    cout<<"Enter the Elements (in ascending order): \n";
    for(i=0; i<n; i++)
        cin>>arr[i];
    cout<<"\nEnter Element to be Searched: ";
    cin>>num;
    first = 0;
    last = n-1;
    middle = (first+last)/2;
    while(first <= last)
    {
        if(arr[middle]<num)
            first = middle+1;
        else if(arr[middle]==num)
        {
            cout<<"\nThe number "<<num<<" found at Position "<<middle+1<<" \nAnd at index "<<middle;
            break;
        }
        else
            last = middle-1;
        middle = (first+last)/2;
    }
    if(first>last)
        cout<<"\nThe number, "<<num<<" is not found in given Array";
    cout<<endl;
    return 0;
}

