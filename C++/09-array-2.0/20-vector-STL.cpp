#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> v;
	v.reserve(100); // initial vector size
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	cout<<endl;
	cout<<v.capacity()<<endl;
	// show
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<", ";
	}
	cout<<endl;
	v.pop_back();//delete
	// show
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<", ";
	}
	cout<<endl;
	// sort
	sort(v.begin(), v.end());
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<", ";
	}
	cout<<endl;

	return 0;
}
/*
v.capacity() // current size of vector
v.size() // current filled size
v.max_size() // maximum size upto which a vector can extent

*/