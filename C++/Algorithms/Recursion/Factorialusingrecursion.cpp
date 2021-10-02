// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int factorial(int n){
 if(n==0 || n ==1) {
     return 1;
 }   
 else {
     int result = factorial(n-1)*n;
     return result;
 }
}
int main() {
    cout << "Enter the number for which you have to find factorial of" <<endl;
    int n;
    cin >> n;
    int calculated = factorial(n);
    cout << calculated;

    return 0;
}