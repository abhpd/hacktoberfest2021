#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    //applying euclids algorithm
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

int main()
{
    //initiating two numbers A,B:
    int a, b;
    cout << "Enter two number :";
    cin >> a >> b;

    //calling the function to find gcd:
    cout << "GCD of " << a << " and " << b << " is ";
    cout << gcd(a, b);
    return 0;
}

/*
    About EUCLIDS ALGORITHM
    Eucilds algorithm is the simplest and fastest way to find GCD(Greatest Common Divisor) 
    of two numbers with its time complexity O(log(max(A,B))) where A and B are the two numbers.

    It says that,
        GCD(A,B) = GCD(B,A%B);
        and when A%B becomes zero A is the GCD of the inital numbers (A,B).

    It also states that,
        -> number of prime numbers less than or equal to n is n/ln(n)
        -> the kth prime number is approximately equal to k*ln(k);
    
*/