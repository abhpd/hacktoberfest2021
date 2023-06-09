#include <iostream>
using namespace std;

int main(){
	int array[2][3], i, j, swap, array2[3][2];
	cout << "Matrix Transpose:\nEnter Matrix Elements\n";
	for(i = 0; i < 2; i++){
		for(j = 0; j < 3; j++){
			cout << "a" << i+1 << j+1 << ": ";
			cin >> array[i][j];
		}
	}
	cout << "original matrix:\n";
	for(i = 0; i < 2; i++){
		for(j = 0; j < 3; j++){
			cout <<array[i][j]<<"\t";
		}
		cout << "\n";
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 2; j++){
			array2[i][j] = array[j][i];
		}
	}
	cout << "Transpose matrix:\n";
	for(j = 0; j < 3; j++){
		for(i = 0; i < 2; i++){
			cout << array2[j][i] << "\t";
		}
		cout << "\n";
	}
	
	return 0;
}
