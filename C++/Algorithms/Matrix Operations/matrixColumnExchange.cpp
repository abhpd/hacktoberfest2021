#include <iostream>
using namespace std;

int main(){
	int array[5][5], i, j;
	cout << "Matrix Column Flip\nEnter Matrix elements:\n";
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			cout << "a" << i+1<<j+1<< ": ";
			cin >> array[i][j];
		}
	}
	cout << "Entered Matrix\n";
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "Flipped Matrix\n";
	for(i = 0; i < 5; i++){
		for(j = 4; j >= 0; j--){
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
	return 0;
}
