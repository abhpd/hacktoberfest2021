#include <bits/stdc++.h>
#include <numeric>
#include <math.h>
using namespace std;

void heapify(vector<int> &heap, int curr, int size);

void heapSort(vector<int> &heap)
{
    for (int i = heap.size() / 2 - 1; i >= 0; i--)
        heapify(heap, i, heap.size());

    for (int i = heap.size() - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        heapify(heap, 0, i);
    }
}

void heapify(vector<int> &heap, int curr, int size)
{
    int largest = curr;
    int l = 2 * curr + 1;
    int r = 2 * curr + 2;

    if (l < size and heap[l] > heap[largest])
        largest = l;

    if (r < size and heap[r] > heap[largest])
        largest = r;

    if (largest != curr)
    {
        swap(heap[curr], heap[largest]);

        heapify(heap, largest, size);
    }
}

int main()
{
    vector<int> arr{12, 11, 13, 5, 6, 7};
    heapSort(arr);
    for (auto &&i : arr)
    {
        cout << i << endl;
    }

    return 0;
}