#include<iostream>
#include <cstring>
using namespace std;
void stairCaseSearch(int a[][10], int R, int C, int key){
	int i=0;
	int j=C-1;
	while(i<R && j>=0){
		if(a[i][j] == key){
			cout<<"Found at {"<<i<<","<<j<<"}\n";
			return;
		}
		else if(a[i][j]>key){
			j--;
		}else{
			i++;
		}
	}
	cout<<"Not found\n";
	return;
}

int main(){
	int a[10][10],R,C,k;
	cin>>R>>C>>k;
	//scan
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>a[i][j];
		}
	}
	//print
	cout<<"Input array: \n";
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<a[i][j]<<" "; // we can match if we want to find some int vale. linear search
		}
		cout<<endl;
	}

	// search k
	stairCaseSearch(a,R,C,k);
	
	cout<<endl;
	return 0;
}

/*

Find a number in 2D array which is sorted along the rows and columns. 
e.g
Ri<Ri+1
Ci<Ci+1
01 02 03 04
05 08 10 11
12 14 15 18
16 17 20 22

Search element 14.
A: Linear search.o(n^2)
B: Binary search on every row.o(nlogn)
C: Stare case searching.o(n)
	1. goto all rows and chk last element.
	2. if equal return.
	3. if > goto next row.
	4. else check on j--

*/