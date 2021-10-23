#include <iostream>
using namespace std;
int multiplyNumbers(int a, int b) {
    if(b == 1){
        return a;
    }
    return a + multiplyNumbers(a,b-1);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << multiplyNumbers(a, b) << endl;
}
