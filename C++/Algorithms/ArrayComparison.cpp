#include <iostream>
using namespace std;

int main(){
	int array1[5], array2[5], i, count = 0;
	cout << "Enter elements of first Array:\n";
	for(i = 0; i < 5; i++){
		cin >> array1[i];
	}
	cout << "Enter elements of second Array:\n";
	for(i = 0; i < 5; i++){
		cin >> array2[i];
	}
	for(i = 0; i < 5; i++){
		if(array1[i] != array2[i]){
			cout << "array item does not match at index " << i << ".\n";
			count++;
		}
	}
	if(count == 0){
		cout << "arrays match each other";
	}
	return 0;
}
