#include<iostream>
using namespace std;
void Print_natural_number(int x,int N){
	if(x>N)return;
	cout<<x<<" ";
	Print_natural_number(x+1,N);
	}
int main(){
	int N;
	cin>>N;
	Print_natural_number(1,N);
	}
