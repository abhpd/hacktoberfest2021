#include <bits/stdc++.h>>
using namespace std;

void bucketSort(float ar[], int n)
{
	vector<float> b[n];

	for (int i = 0; i < n; i++) {
		int bi = n * ar[i]; 
		b[bi].push_back(ar[i]);
	}
  for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());

	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			ar[index++] = b[i][j];
}

int main()
{
  int z;
  cout<<"Enter the size of array";
  cin>>z;
	float arr[z];
  for(int i=0;i<z;i++)
    cin>>arr[i];
	bucketSort(arr, z);

	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
