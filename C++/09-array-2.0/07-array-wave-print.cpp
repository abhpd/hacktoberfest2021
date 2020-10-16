#include<iostream>
#include <cstring>
using namespace std;

void waveColWise(int a[10][10], int R, int C ){
	for(int j=0;j<C;j++){
		if(j&1){ // odd
			for(int i=R-1;i>=0;i--){
				cout<<a[i][j]<<" "; // we can match if we want to find some int vale.
			}
		}else{ // even column
			for(int i=0;i<R;i++){
				cout<<a[i][j]<<" "; // we can match if we want to find some int vale.
			}
		}
	}
}

void waveRowWise(int a[10][10], int R, int C){
	for(int j=0;j<R;j++){
		if(j&1){ // odd
		    for(int i=C-1;i>=0;i--){
				cout<<a[j][i]<<" "; // we can match if we want to find some int vale.
			}
			
		}else{ // even column
			for(int i=0;i<C;i++){
				cout<<a[j][i]<<" "; // we can match if we want to find some int vale.
			}
		}
	}
}
int main(){
	int a[10][10],R,C, v=1;
	cin>>R>>C;
	//scan
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			//cin>>a[i][j];
			a[i][j] = v++;
		}
	}
	//print
	cout<<"Input array: \n";
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<a[i][j]<<"\t"; // we can match if we want to find some int vale.
		}
		cout<<endl;
	}
	// wave print- up then down repeatidly
	cout<<"Row wave: ";
	waveRowWise(a,R,C);
	cout<<"\nCol wave: ";
	waveColWise(a,R,C);
	cout<<endl;
	return 0;
}

/*

Input:
3 3
1 2 3 4 5 6 7  8 9

Output:
Unique pattern
1 2 3
4 5 6
7 8 9
Alternate pattern
1 4 7 8 5 2 3 6 9

*/