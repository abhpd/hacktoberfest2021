/*You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).*/

#include <iostream>
using namespace std;

void swapElements(int *input, int i, int j) {
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}
void reverse(int *input, int start, int end) { 
    int i = start, j = end;
    while(i < j) {
        swapElements(input, i, j);
        i++;
        j--;
    }
}
void rotate(int *input, int d, int n)
{
  
    if(d >= n && n != 0) { 
        d = d % n;
    }
    else if (n == 0) {
        return;
    }
    reverse(input, 0, n - 1);
    reverse(input, 0, n - d - 1);
    reverse(input, n - d, n - 1);
}
int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}