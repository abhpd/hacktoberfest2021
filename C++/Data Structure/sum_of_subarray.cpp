#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter SIZE of Array: ";
    cin >> n;
    int arr[n];
    cout << "Enter Elements of Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int current_sum = 0;
    for (int i = 0; i < n; i++)
    {
        current_sum = 0;
        for (int j = i; j < n; j++)
        {
            current_sum = current_sum + arr[j];
            cout << current_sum << endl;
        }
    }

    return 0;
}