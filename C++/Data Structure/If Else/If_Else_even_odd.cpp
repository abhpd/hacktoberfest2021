#include<iostream>
using namespace std;

void checkOddEven(int n)
{
    if(n%2 == 0)
    cout << "Even";
    else
    cout << "Odd";
}

int main()
{
  
  int number;

  
  cout << "Enter an Integer: " ;
  cin >> number;

  checkOddEven(number);

  return 0;
}