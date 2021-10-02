// Bitonic Search : Search in array which increases and then decreases in value.
#include <bits/stdc++.h>
using namespace std;

int ascendingBinarySearch(vector<int> v, int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == key)
            return mid;
        if (v[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int descendingBinarySearch(vector<int>v, int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == key)
            return mid;
        if (v[mid] < key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int findBitonicPoint(vector<int> v, int n, int l, int r)
{
    int mid;
    int bitonicPoint = 0;
    mid = (r + l) / 2;
    if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1])
    {
        return mid;
    }

    else if (v[mid] > v[mid - 1] && v[mid] < v[mid + 1])
    {
        bitonicPoint = findBitonicPoint(v, n, mid, r);
    }

    else if (v[mid] < v[mid - 1] && v[mid] > v[mid + 1])
    {
        bitonicPoint = findBitonicPoint(v, n, l, mid);
    }
    return bitonicPoint;
}

int searchBitonic(vector<int> v, int n, int key, int index)
{
    if (key > v[index])
        return -1;

    else if (key == v[index])
        return index;

    else
    {
        int temp = ascendingBinarySearch(v, 0, index - 1, key);
        if (temp != -1)
        {
            return temp;
        }
        return descendingBinarySearch(v, index + 1, n - 1, key);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements in array : ";
    cin >> n;
    cout << "\nEnter a Bitonic array : "<<endl;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int l = 0;
    int r = n - 1;
    int index;
    int key;
    cout << "\nEnter element you want to search : ";
    cin >> key;

    index = findBitonicPoint(v, n, l, r);

    int x = searchBitonic(v, n, key, index);

    cout<<"Your element was found at "<<x<<endl;
}