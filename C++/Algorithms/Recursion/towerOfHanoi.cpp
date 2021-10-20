#include <iostream>
using namespace std;

void towers(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        cout << "move disk 1 from peg " << from << " to peg " << to << endl;
        return;
    }
    towers(n - 1, from, aux, to);
    cout << "move disk " << n << " from peg " << from << " to peg " << to << endl;
    towers(n - 1, aux, to, from);
}

int main()
{
    int n;
    cout << "Enter the number of disks in tower: ";
    cin >> n;
    towers(n, 'A', 'C', 'B');
    return 0;
}
