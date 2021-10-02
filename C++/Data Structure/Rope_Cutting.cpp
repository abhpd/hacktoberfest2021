// C++ program to print how many
// Ropes are Left After Every Cut
#include <bits/stdc++.h>
using namespace std;

// Function print how many Ropes are
// Left AfterEvery Cutting operation
void cuttringRopes(int Ropes[], int n)
{
	// sort all Ropes in increase
	// of there length
	sort(Ropes, Ropes + n);

	int singleOperation = 0;

	// min length rope
	int cuttingLenght = Ropes[0];

	// now traverse through the given
	// Ropes in increase order of length
	for (int i = 1; i < n; i++)
	{
		// After cutting if current rope length
		// is greater than '0' that mean all
		// ropes to it's right side are also
		// greater than 0
		if (Ropes[i] - cuttingLenght > 0)
		{
			// print number of ropes remains
			cout << (n - i) << " ";
			
			// now current rope become
			// min length rope
			cuttingLenght = Ropes[i];
			singleOperation++;
		}
	}
	if (singleOperation == 0)
		cout << "0 ";
}
int main()
{
	int Ropes[] = { 5, 1, 1, 2, 3, 5 };
	int n = sizeof(Ropes) / sizeof(Ropes[0]);
	cuttringRopes(Ropes, n);
	return 0;
}

