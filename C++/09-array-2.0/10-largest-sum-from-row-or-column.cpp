#include<iostream>
#include <cstring>
using namespace std;


int main(){
	int a[][3] ={{1,2,3},{4,5,0},{-5,3,1}};
	int rsum=0, csum=0,maxsum=0;
	for(int i=0;i<3;i++){
		rsum=0;
		csum=0;
		for(int j=0;j<3;j++){
			rsum += a[i][j];
			csum += a[j][i];
		}
		csum = max(csum, rsum);
		maxsum = max(csum,maxsum);
	}
	cout<<maxsum<<endl;
	
	return 0;
}

/*
 1 2 3 | 6
 4 5 0 | 9
-5 3 1 |-1
--------
 0 10 4
*/