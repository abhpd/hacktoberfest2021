#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool compare(string a, string b){
	if(a.length() == b.length()){
		return a>b; // if same length descending
	}else{
		return a.length()<b.length(); //lexicographically 
	}
}

int main(){
	string a ="Hello Md";
	cout<<a<<endl;

	string b;
	getline(cin,b); //std::getline(), takes sentences
	cout<<b<<endl;

	// string array
	cout<<"String Array: ";
	string s[10] = {"Apple", "Mango", "Guava", "Banana", "Papayaa"};
	int n=5;
	// for(int i=0;i<n;i++)
	// 	getline(cin, s[i]);
	cout<<"\n Original Array: ";
	for(int i=0;i<n; i++){
		cout<<s[i]<<", ";
	}
	cout<<endl;

	// sorting
	cout<<"\n Sorted Array: ";
	sort(s,s+n, compare);
	for(int i=0;i<n; i++){
		cout<<s[i]<<", ";
	}
	cout<<endl;

	// string to be searched
	cout<<"String to be searched: ";
	string key;
	getline(cin,key);

	// linear search
	cout<<"Linear Search: ";
	for(int i=0;i<n;i++){
		if(s[i] == key){
			cout<<"Found at: "<<i+1<<endl;
			return 0;
		}
	}
	cout<<"Not Found\n";


	
	cout<<endl;
	return 0;
}

/*

Todo:
	take string
	search for a string
	

*/