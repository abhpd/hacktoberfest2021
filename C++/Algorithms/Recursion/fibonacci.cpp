#include<iostream>
using namespace std;

int fibonacci(int order){
    if(order <= 1){
        return order;
    }
    return fibonacci(order-1) + fibonacci(order-2);
}

int main(){
    int order = 10;
    for(int i=1;i<order;i++){
        cout << fibonacci(i) << endl;
    }
}
