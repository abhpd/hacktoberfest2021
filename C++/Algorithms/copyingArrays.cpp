#include <iostream>
using namespace std;

int main(){
	int i;
	int array[10] = {1,2,3,4,5,6,67,7,8,1}, array2[10];
	for(i = 0; i < 10; i ++){
		array2[i] = array[i];
		cout << array2[i];
	}
	return 0;
}
