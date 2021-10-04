#include <iostream>
#include <climits>
using namespace std;

int main()
{

    int n;
    cout << "Enter the number of elements in array " << endl;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxNo = INT_MIN;
    int minNo = INT_MAX;

    for (int i = 0; i < n; i++)
    {

        maxNo = max(maxNo, arr[i]);
        minNo = min(minNo, arr[i]); /* if(arr[i]>maxNo){
                                              maxNo=arr[i];
                                            }
                                             if(arr[i]<minNo){
                                              minNo=arr[i];  */
    }

    cout << "The max value in array is " << maxNo << " "
         << "\nThe min value in array is " << minNo << endl;
    return 0;
}