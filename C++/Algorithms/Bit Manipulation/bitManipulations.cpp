#include <bits/stdc++.h>
using namespace std;

int returnFirstSetBit(int n){
    return  n ^ (n&(n-1));
    // return log2(n & -n) + 1;
}
int clearAllBits(int n, int i){
   int  m=(1<<i)-1;
    return n&m;
}
int turnOnIthBit(int n, int i){
   
    n=n|(1<<i);
    return n;
    
}
int turnOffIthBit(int n, int i){
    n=n& ~(1<<i);
    return n;
}
int main() {
	int n, i;
	cin >> n >> i;
	cout<< clearAllBits(n, i) <<endl;		
	return 0;
}

