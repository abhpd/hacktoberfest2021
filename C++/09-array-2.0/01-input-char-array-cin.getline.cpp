#include <iostream>
using namespace std;

int main() {
   	char a[5]; // contains garbage values
   	cout<<"A: "<<a<<sizeof(a)/sizeof(char)<<endl;

   	char b[] ={'a', 'b', 'c', 'd', 'e'}; // can end with null or garbage value
   	cout<<"B: "<<b<<sizeof(b)/sizeof(char)<<endl;

   	char c[] ={'a', 'b', 'c', 'd', 'e', '\0'}; // best practice to add null at end
   	cout<<"C: "<<c<<sizeof(c)/sizeof(char)<<endl;

   	char d[] = "hello world"; //size+1
   	cout<<"D: "<<d<<sizeof(d)/sizeof(char)<<endl;

   	// storing char
   	char e[100];
   	cin>>e; // it can also read boolean string , without spaces, tab etc.
   	cout<<"E: "<<e<<sizeof(e)/sizeof(char)<<endl;

   	// strong using cin.getline()
   	char f[100];
   	// cin.getline(arr, sizeofarray, delimiter) default delimeter is '\n'
   	cin.getline(f,100);
   	cout<<"F: "<<f<<sizeof(f)/sizeof(char)<<endl;;

   	// read pragraph
   	char par[1000];
   	cin.get(par, 1000, '.'); // when it finds . then stops, at max 1000 char can be read
   	cout<<"Par: "<<par<<sizeof(par)/sizeof(char)<<endl;;

    return 0;
}


/*

Input: 

i am from e
you are from f
what about
the paragraph
you are reading.

Output:
    
A: 5
B: abcde5
C: abcde6
D: hello world12
E: i100
F:  am from e100
Par: you are from f
what about
the paragraph
you are reading1000

*/