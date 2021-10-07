#include<bits/stdc++.h>
#include<vector>
using namespace std;
 
void search(vector<int> arr, int search_Element)
{
    int left = 0;
    int length = arr.size();
    int position = -1;
      int right = length - 1;
       
    // Run loop from 0 to right
    for(left = 0; left <= right;)
    {
         
        // If search_element is found with
        // left variable
        if (arr[left] == search_Element)
        {
             
            position = left;
            cout << "Element found in Array at "
                 << position + 1 << " Position with "
                 << left + 1 << " Attempt";
                
            break;
        }
       
        // If search_element is found with
        // right variable
        if (arr[right] == search_Element)
        {
            position = right;
            cout << "Element found in Array at "
                 << position + 1 << " Position with "
                 << length - right << " Attempt";
                
            break;
        }
        left++;
        right--;
    }
 
    // If element not found
    if (position == -1)
        cout << "Not found in Array with "
             << left << " Attempt";
}
 
// Driver code
int main()
{
    vector<int> arr{ 1, 2, 3, 4, 5 };
    int search_element = 5;
     
    // Function call
    search(arr, search_element);
}
