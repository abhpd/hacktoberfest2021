#include <bits/stdc++.h>
using namespace std;
/*https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2612*/
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	long long casos, a,b,c;
	cin>>casos;
	while(casos--){
		cin>>a>>b>>c; bool es = 0;
		
		for(int i = -100; i<=100; i++){
			if(i*i > c) continue;
			for(int j = -100; j<=100; j++){
				if(i==j || i*i +j*j > c) continue;
				for(int k = -100; k<=100; k++){
					if(k==i || j == k ) continue;
						if((i*i + j*j + k*k) == c && i*j*k == b && i+j+k == a){
							
							es =1;
							cout<<i<<" "<<j<<" "<<k<<"\n"; 
							goto fin;
						}
				}
			}
		}
		fin:
		if (!es) cout<<"No solution.\n";
	}
	return 0;
}
