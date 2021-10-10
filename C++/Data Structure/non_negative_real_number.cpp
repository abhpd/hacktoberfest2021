#include <bits/stdc++.h>

using namespace std;

float x = 0, y = 0, z = 0, value;


int main() {

	scanf("%f %f %f", &x, &y, &z);
	value = (x*x) + (y*y);
	
	if(value == (z*z)){
		printf("TRUE");
	}else{
		printf("FALSE");
	}
	
	printf("\n");

}
