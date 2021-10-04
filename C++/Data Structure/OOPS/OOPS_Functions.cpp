#include <iostream>
using namespace std;

class student
{

public:
    string name;
    int age;
    bool gender;

    student()
    {
        cout << "Default Constructor" << endl;
    }

    student(string s, int a, int g)
    {
        cout << "Parameterised Constructor" << endl;
        name = s;
        age = a;
        gender = g;
    }

    student(student &a)
    {
        cout << "Copy Constructor" << endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }
    ~student()
    {
        cout << "Destructor called " << endl;
    }

    bool operator==(student &a)
    {

        if (name == a.name &&age == a.age &&gender == a.gender)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    student a("Hardeep", 19, 0);
    student b;
    student c = a;

    if (c == a)
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not Same" << endl;
    }

    return 0;
}