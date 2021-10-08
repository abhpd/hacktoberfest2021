/*
Title: Merge Sort
Description: Sort an array A using Merge Sort. Change in the input array itself. So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3

Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
2 1 5 2 3

Sample Output 2 :
1 2 2 3 5 
*/

#include <iostream>
using namespace std;

//SI - START INDEX , EI - END INDEX
void merge(int input[], int si, int ei)
{

    //FINDING MID
    int mid = (si + ei) / 2;
    int size = ei - si + 1;

    //TAKING TEMP ARR TO STORE THE SORTED ARRAY FROM THE TWO HALVES
    int output[size];

    //FIRST HALF: SI TO MID, SECOND HALF: MID TO EI
    int i = si, j = mid + 1, index = 0;

    //RUN THE MAIN LOOP, TILL ANY ONE OF THE HALF GETS EXHAUSTED FIRST
    while (i <= mid && j <= ei)
    {

        //PUT THE SMALLER ELEMENT IN OUR OUTPUT ARRAY
        if (input[i] <= input[j])
        {
            output[index] = input[i];
            index++;
            i++;
        }
        else
        {
            output[index] = input[j];
            index++;
            j++;
        }
    }

    //PUSH THE REMAINING HALF ELEMENTS AS IT IS TO THE OUTPUT ARR
    while (i <= mid)
        output[index++] = input[i++];
    while (j <= ei)
        output[index++] = input[j++];

    //COPY BACK FROM OUR TEMP ARR TO ORIGINAL INPUT ARR
    index = 0;
    for (int i = si; i <= ei; i++)
    {
        input[i] = output[index++];
    }
}

//HELPER FUNCTION
void helper(int input[], int si, int ei)
{

    //BASE CASE
    if (si >= ei)
    {
        return;
    }

    int mid = (si + ei) / 2;

    //USE RECURSION TO SORT THE FIRST AND SECOND HALF
    helper(input, si, mid);
    helper(input, mid + 1, ei);

    //USE THE MERGE FUNCTION TO SORT THE TWO SORTED HALVES
    merge(input, si, ei);
}

void mergeSort(int input[], int size)
{
    if (size <= 1)
    {
        return;
    }
    else
    {
        helper(input, 0, size - 1);
    }
}

int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
}