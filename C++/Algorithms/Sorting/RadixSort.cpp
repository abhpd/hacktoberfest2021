#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &Arr, int r, int exp, int min)
{
    int bucket;
    vector<int> buckets(r);
    vector<int> output(Arr.size());

    // Initialize bucket
    for (int ctr = 0; ctr < r; ctr++)
    {
        buckets[ctr] = 0;
    }

    // Count Frequencies
    for (int ctr = 0; ctr < Arr.size(); ctr++)
    {
        bucket = (int)(((Arr[ctr] - min) / exp) % r);
        buckets[bucket]++;
    }

    // Compute cumulates
    for (int i = 1; i < r; i = i + 1)
    {
        buckets[i] += buckets[i - 1];
    }

    // Move the records
    for (int i = Arr.size() - 1; i >= 0; i = i - 1)
    {
        bucket = (int)(((Arr[i] - min) / exp) % r);
        output[--buckets[bucket]] = Arr[i];
    }

    // Copy back to the original array
    for (int i = 0; i < Arr.size(); i = i + 1)
    {
        Arr[i] = output[i];
    }
}

void rsort(vector<int> &A, int r)
{
    if (A.size() == 0)
    {
        return;
    }

    // Minimum and Maximum values
    int min = A[0];
    int max = A[0];

    for (int ctr = 0; ctr < A.size(); ++ctr)
    {
        if (A[ctr] < min)
            min = A[ctr];
        else if (A[ctr] > max)
            max = A[ctr];
    }

    /*
         * Perform counting sort on each exponent or digit, starting at the least
         * significant digit
         */
    int exp = 1;
    for (; (max - min) / (exp) >= 1;)
    {
        countSort(A, r, exp, min);
        exp = exp * r;
    }
}

int main()
{
    vector<int> ArrayToBeSorted = {-9, -1, 10, -2, 12, 102, -3, 12, 39, 8, 2, 6};
    cout << "Original Array: ";
    for (int i = 0; i < ArrayToBeSorted.size(); i = i + 1)
    {
        cout << ArrayToBeSorted[i] << " ";
    }

    rsort(ArrayToBeSorted, 10);

    cout << "\n\nSorted Array: ";
    for (int i = 0; i < ArrayToBeSorted.size(); i = i + 1)
    {
        cout << ArrayToBeSorted[i] << " ";
    }
    cout << "\n";

    return 0;
}
