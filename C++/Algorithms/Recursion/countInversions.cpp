#include <iostream>
using namespace std;
int main()
{
cout << "Enter the no of element for inversion: " << endl;
int n;
cin >> n;
int ar[10];
cout << "Enter the all elements: " << endl;
for (int i = 0; i < n; i++)
{
cin >> ar[i];
}
int count = 0;
cout << "The inversions are: ";
for (int i = 0; i < n; i++)
{
for (int j =i+1; j < n; j++)
{
if (ar[j] < ar[i])
{
cout<<"("<< ar[i] << "," << ar[j] <<")"<<" ";
count++;
}
}
}
cout <<"\nThe no of inversion is: "<< count;
return 0;
}

