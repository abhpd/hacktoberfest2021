#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPalindrome(int n)
{
    int temp = n, number = 0;

    while (temp > 0)
    {
        number = number * 10 + temp % 10;
        temp = temp / 10;
    }

    if (number == n)
    {
        return true;
    }
    return false;
}

int findPalindromicSubarray(vector<int> arr, int k)
{
    int num = 0;

    for (int i = 0; i < k; i++)
    {
        num = num * 10 + arr[i];
    }

    if (isPalindrome(num))
    {
        return 0;
    }

    for (int j = k; j < arr.size(); j++)
    {
        num = (num % (int)pow(10, k - 1)) * 10 + arr[j];

        if (isPalindrome(num))
        {
            return j - k + 1;
        }
    }
    return -1;
}

int main()
{

    vector<int> arr = {2, 3, 5, 1, 1, 5};
    int k = 4;

    int ans = findPalindromicSubarray(arr, k);

    if (ans == -1)
    {
        cout << "Palindromic Sbarray does not exist" << endl;
    }
    else
    {
        for (int i = ans; i < ans + k; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}