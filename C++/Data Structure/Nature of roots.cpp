# Data-structures
// C++ program to check the nature of the roots 

#include <bits/stdc++.h> 
using namespace std; 

// BVA for nature of roots of a quadratic equation 
void nature_of_roots(int a, int b, int c) 
{ 

	// If a = 0, D/2a will yield exception 
	// Hence it is not a valid Quadratic Equation 
	if (a == 0) { 
		cout << "Not a Quadratic Equation"
			<< endl; 
		return; 
	} 

	int D = b * b - 4 * a * c; 

	// If D > 0, it will be Real Roots 
	if (D > 0) { 
		cout << "Real Roots" << endl; 
	} 

	// If D == 0, it will be Equal Roots 
	else if (D == 0) { 
		cout << "Equal Roots" << endl; 
	} 

	// If D < 0, it will be Imaginary Roots 
	else { 
		cout << "Imaginary Roots" << endl; 
	} 
} 

// Function to check for all testcases 
void checkForAllTestCase() 
{ 

	cout << "Testcase"
		<< "\ta\tb\tc\tActual Output"
		<< endl; 
	cout << endl; 
	int a, b, c; 
	int testcase = 1; 
	while (testcase <= 13) { 
		if (testcase == 1) { 
			a = 0; 
			b = 50; 
			c = 50; 
		} 
		else if (testcase == 2) { 
			a = 1; 
			b = 50; 
			c = 50; 
		} 
		else if (testcase == 3) { 
			a = 50; 
			b = 50; 
			c = 50; 
		} 
		else if (testcase == 4) { 
			a = 99; 
			b = 50; 
			c = 50; 
		} 
		else if (testcase == 5) { 
			a = 100; 
			b = 50; 
			c = 50; 
		} 
		else if (testcase == 6) { 
			a = 50; 
			b = 0; 
			c = 50; 
		} 
		else if (testcase == 7) { 
			a = 50; 
			b = 1; 
			c = 50; 
		} 
		else if (testcase == 8) { 
			a = 50; 
			b = 99; 
			c = 50; 
		} 
		else if (testcase == 9) { 
			a = 50; 
			b = 100; 
			c = 50; 
		} 
		else if (testcase == 10) { 
			a = 50; 
			b = 50; 
			c = 0; 
		} 
		else if (testcase == 11) { 
			a = 50; 
			b = 50; 
			c = 1; 
		} 
		else if (testcase == 12) { 
			a = 50; 
			b = 50; 
			c = 99; 
		} 
		else if (testcase == 13) { 
			a = 50; 
			b = 50; 
			c = 100; 
		} 
		cout << "\t" << testcase << "\t"
			<< a << "\t" << b << "\t"
			<< c << "\t"; 
		nature_of_roots(a, b, c); 
		cout << endl; 
		testcase++; 
	} 
} 

// Driver Code 
int main() 
{ 
	checkForAllTestCase(); 
	return 0; 
} 
