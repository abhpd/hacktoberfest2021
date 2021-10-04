#include <iostream>
using namespace std;

class ApnaCollege
{

public:
    void func()
    {
        cout << " I am a funnction with no arguments " << endl;
    }
    void func(int x)
    {
        cout << " I am a funnction with int  arguments " << endl;
    }

    void func(double x)
    {
        cout << " I am a funnction with double  arguments " << endl;
    }
};

int main()
{
    ApnaCollege obj;
    obj.func();
    obj.func(4);
    obj.func(6.2);
}