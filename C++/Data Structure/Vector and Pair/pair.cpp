#include <iostream>
using namespace std;

int main()
{

    std::pair<int, char> p;
    p.first = 3;
    p.second = 'h';

    std::cout << p.first << p.second << std::endl;

    return 0;
}