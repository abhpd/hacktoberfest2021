#include<iostream>
#include <cstring>
using namespace std;

void spiralPrintAntiClock(int a[][10], int R, int C){
	int sR = 0, eR = R-1, sC = 0, eC =C-1;
	while(sR<=eR and sC<=eC){
		// print start row, sr to sc
		for(int i=sR;i<=eR; i++)
			cout<<a[i][sC]<<", ";
		sC++;

		// print end col, sR to eR
		for(int i=sC;i<=eC; i++)
			cout<<a[eR][i]<<", ";
		eR--;

		// print end row, ec to sc
		if(eC>sC){
			for(int i=eR;i>=sR; i--)
				cout<<a[i][eC]<<", ";
			eC--;
		}

		// print start col, er to sr
		if(sC<eC){
			for(int i=eC;i>=sC; i--)
				cout<<a[sR][i]<<", ";
			sR++;	
		}
	}
	return;
}

void spiralPrintClock(int a[][10], int R, int C){
	int sR = 0, eR = R-1, sC = 0, eC =C-1;
	while(sR<=eR and sC<=eC){
		// print start row, sr to sc
		for(int i=sC;i<=eC; i++)
			cout<<a[sR][i]<<", ";
		sR++;

		// print end col, sR to eR
		for(int i=sR;i<=eR; i++)
			cout<<a[i][eC]<<", ";
		eC--;

		// print end row, ec to sc
		if(sR<=eR){
			for(int i=eC;i>=sC; i--)
				cout<<a[eR][i]<<", ";
			eR--;
		}

		// print start col, er to sr
		if(sC<=eC){
			for(int i=eR;i>=sR; i--)
				cout<<a[i][sC]<<", ";
			sC++;	
		}
	}
	return;
}

int main(){
	int a[10][10],R,C, value=1;
	cin>>R>>C;
	//scan
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			//cin>>a[i][j];
			a[i][j]=value++;
		}
	}
	//print
	cout<<"Input array: \n";
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}

	// spiral print
	spiralPrintClock(a,R,C);
	
	cout<<endl;
	return 0;
}

/*

Spiral print

e.g
Input:
4 4

01 02 03 04
05 08 10 11
12 14 15 18
16 17 20 22

Output:
1 2 3 4 11 18 22 20 17 16 12 5 8 10 15 14

2hr7min

*/