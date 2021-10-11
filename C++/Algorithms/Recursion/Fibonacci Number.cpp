// c++ code for finding nth fibonacci number
/*
The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..
  problem statement: Given n find nth fibonacci number.
    
    e.g-
     INPUT: n=3
     OUTPUT: 2
     
*/

// code using recursion

#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
	if (n <= 1) return n;
	return fib(n-1) + fib(n-2);
}

int main ()
{
	int n;
  cin>>n;
	cout << fib(n);
	return 0;
}
