#include<iostream>
#include <cstring>
using namespace std;

int main(){
	char a[][3] = {{'a', 'b', 'c'},{'d', 'e', 'f'}};
	cout<<a[0][0]<<endl;
	cout<<a[0]<<endl; //print abcdef + garbage. it also means that array is stored continuously.
	// but for int array it will print only address just because char address is handle differently by cout.
	
	char word[10][100] = { // max 10 rows and 100 columns
		"Apple",
		"I am MD",
		"Mango Shake",
		"Papaya"
	};
	cout<<word[0]<<endl; // row 0 address->Apple
	cin.getline(word[3],100);
	cout<<word[3]<<endl;
	return 0;
}

/*

1. Number of rows are optional in array initialization
	while number of column is mandatory
	e.g a[][3] = {{1,2,3},{4,5,6}} => 2 rows and 3 columns

2. In 2d array a[0] is address of row 0 and a[0][0] is 1 element of matrix i.e row 0 col 0.
	in case of a[0] if it is char array it will print till null char is found.


*/