//C++ program to find factorial using Recursive approach

#include <iostream>
using namespace std;

int main()
{
   int number;
   long factorial = 1;

   cout << "Enter number: ";
   cin >> number;

   for (int i = 1; i <= number; i++ )
   {
      factorial = factorial * i;
   }

   cout << "Factorial of " << number << ": " << factorial << endl;
   return 0;
}
