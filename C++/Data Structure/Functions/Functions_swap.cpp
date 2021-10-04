#include <iostream>
using namespace std;

void swap(int a, int b)
{
    int temp;
    
    temp=a;
    a=b;
    b=temp;

    cout<<"After swap "<<a<<" "<<b<<endl;
}

int main()
{

    int a, b;
    cout << "Enter two values " << endl;
    cin >> a >> b;
    cout<<"Before swap "<<a<<" "<<b<<endl;

    swap(a, b);

    return 0;
}