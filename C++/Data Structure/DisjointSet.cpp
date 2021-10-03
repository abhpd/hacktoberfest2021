#include <bits/stdc++.h>
#define ll long long int
const int SIZE = 1e5 + 5;

using namespace std;

int p[SIZE]; //parent
int r[SIZE];//rank

int get(int a) {
	return p[a] = (p[a] == a ? a : get(p[a]));
}

void uniun(int a, int b) {
	int sa = get(a);
	int sb = get(b);
	if (r[sa] == r[sb])
		r[sa]++;
	if (r[sa] > r[sb])
		p[sb] = sa;
	else
		p[sa] = sb;
}
int main() {
    int n = 5; //size of array
    int m  = 5; //queries
    for (int i = 0; i < n; ++i)
        p[i] = r[i] = i;
    uniun(1, 2);
    cout<<"Parent of 1 is "<<get(1);
    return 0;
}