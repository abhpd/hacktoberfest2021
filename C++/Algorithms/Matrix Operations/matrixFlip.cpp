#include <iostream>
using namespace std;

int main(){
	cout << "Matrix Row Flip:\nEnter Matrix Elements\n";
	int array[2][3], i, j;
	for(i = 0; i < 2; i++){
		for(j = 0; j < 3; j++){
			cout << "a" << i+1 << j+1 << ": ";
			cin >> array[i][j];
		}
	}
	cout << "original matrix\n";
	for(i = 0; i < 2; i++){
		for(j = 0; j < 3; j++){
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "Flipped matrix\n";
	for(i = 1; i >= 0; i--){
		for(j = 0; j < 3; j++){
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
	return 0;
}
