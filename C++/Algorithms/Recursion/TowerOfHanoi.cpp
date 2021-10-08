#include <bits/stdc++.h>
using namespace std;


// function to implement tower of hanoi problem recursively
//                 Steps---
// Step 1 − Move n-1 disks from source to spare
// Step 2 − Move nth disk from source to destination
// Step 3 − Move n-1 disks from spare to destination


void towerOfHanoi(int disks, char src, char dest, char spare){
	// Base case
	if(disks == 1){
		cout << "Move disk 1 from rod " << src << " to rod " << dest << endl;
		return;
	}

	towerOfHanoi(disks-1, src, spare, dest);
	cout << "Move disk " << disks << " from rod " << src << " to rod " << dest << endl;
	towerOfHanoi(disks-1, spare, dest, src);
}


int main(){
	int n;
	cout << "Enter number of disks: ";
	cin >> n;

	// A -- source rod
	// B -- auxillary rod
	// C -- destination rod
	towerOfHanoi(n,'A','C','B');

	return 0;
}