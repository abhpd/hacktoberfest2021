#include<iostream>
#include <cstring>
using namespace std;


int main(){
	char a[10][100], key[100];// 10 rows each of 100 cells/char, one string to be searched.
	int n;
	cin>>n;
	cin.ignore(); // to ignore the 'enter' after n
	// other wise it will read enter and it will be 1st string.
	for(int i=0;i<n;i++)
		cin.getline(a[i], 100); // each row can be filled upto 100 chars

	// output
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}

	cout<<"Enter element to be searched: ";
	cin.getline(key,100);

	// linear search
	for(int i=0;i<n;i++){
		// we can compare string using loops or inbuilt function strcmp().
		if(strcmp(key, a[i]) == 0){
			cout<<"Found at "<<i<<endl;
			return 0;
		}
	}
	cout<<"Not Found\n";

	return 0;
}

/*

*/