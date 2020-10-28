#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
#define INF 10000

// global	
int val = 0;
int num_coins = 0; 
int aux = 0;
vector<int> coins;


void MinimumCoins () {
	// each value in the array represents the minimum number of coins for each amount
	// val == 4 --> MEMO[4] = [a,b,c,d]
	int MEMO[val];
	
	// since we’re dealing with minimums, values are often initialized to Infinity (∞). 
	// the logic is that at this moment, the minimum number of coins to make each amount is infinite:
	for (int i = 0; i < val+1; i++) 
		MEMO[i] = INF; // c++ infinite
	MEMO[0] = 0; // 0 is always 0 

	// i --> sum
	// j --> coin index
	for (int i = 1; i < val+1; i++) {
		for (int j = 0; j < num_coins; j++) {
			if (coins[j] <= i)
				MEMO[i] = min(MEMO[i], MEMO[i-coins[j]]+1);
		}
	}

	// // starts at 1 because 0 is 0
	// for (int i = 1; i < val-1; i++) {
	// 	int sub = min (MEMO[i-1]+1, MEMO[i]);
	// 	MEMO[i] = sub;
	// }	

	if (MEMO[val] == INF)
		MEMO[val] = -1;
	
	//printf("\n");
	///for (int i = 0; i < val; i++)
		//printf ("%d ", MEMO[i]);

	//printf("\n");

	printf ("%d\n",MEMO[val]);
	return;
}

int main (void) {

	int tests = 0;
	cin >> tests;

	while (tests) {
		cin >> val;
		cin >> num_coins;
		for (int i = 0; i < num_coins; i++) {
			cin >> aux;
			coins.push_back(aux);
		}
		MinimumCoins ();
		coins.clear();
		tests--;
	}
	return 0;
}
