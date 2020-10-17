#include<iostream>
#include<string>
using namespace std;

void formatting(string str,string out, int i){
	out = out + str[i];
	//base case
	if(i == str.length()){
		cout<< out<< endl;
		return;
	}
	//recursive case
	if(str[i] == str[i+1]){
		out = out + "*";
	
	}

	formatting(str,out,i+1);
	
}

int main(){
	string str;
	cin>> str;
	string out;
	formatting(str,out,0);
	
	return 0;
}

// Input Format:
// Enter a String

// Output Format:
// Display the resulting string (i.e after inserting (*) b/w all the duplicate characters)

// Sample Input:
// hello
// Sample Output:
// hel*lo
// Explanation:
// We insert a "*" between the two consecutive 'l' .
