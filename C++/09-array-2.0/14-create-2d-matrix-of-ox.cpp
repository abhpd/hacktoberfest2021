#include<iostream>
#include <cstring>
using namespace std;

void spiralPrint(int n){
	int sR = 0, eR = n-1, sC = 0, eC =n-1 ,iteration=1;
	char pattern, a[n][n];
	while(sR<=eR and sC<=eC){
		if(iteration&1)
			pattern = '0';
		else
			pattern='x';
		// print start row, sr to sc
		for(int i=sC;i<=eC; i++)
			a[sR][i] = pattern;
		sR++;

		// print end col, sR to eR
		for(int i=sR;i<=eR; i++)
			a[i][eC] = pattern;
		eC--;

		// print end row, ec to sc
		if(eR>sR){
			for(int i=eC;i>=sC; i--)
				a[eR][i] = pattern;
			eR--;
		}

		// print start col, er to sr
		if(sC<eC){
			for(int i=eR;i>=sR; i--)
				a[i][sC] = pattern;
			sC++;	
		}
		iteration++;
	}
	// print()
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return;
}

int main(){
	int n;
	cin>>n;
	// spiral print
	spiralPrint(n);
	
	return 0;
}

/*
N<=10

N=5
00000
0xxx0
0x0x0
0xxx0
00000
Hint: use spiral print
*/