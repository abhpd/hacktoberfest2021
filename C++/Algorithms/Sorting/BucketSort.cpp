// We can use bucket_sort when data is in a range

#include<bits/stdc++.h>
using namespace std;

class Student{
	public:
	int marks;
	string name;
};

void print(Student s){
	cout<<s.marks<<" "<<s.name;
}

void bucket_sort(Student s[], int n){
	
	// assuming marks are in range 0-100
	vector<Student> v[101];
	
	for(int i=0; i<n; i++){
		int m = s[i].marks;	
		v[m].push_back(s[i]); // O(n)
	}
	
	// iterate over the vector and print students
	
	for(int i=0; i<101; i++){
		// v[i] is the vector
		// print all students of v[i]
		if(v[i].size()){
			for(int j=0; j<v[i].size(); j++){
				print(v[i][j]);
				cout<<endl;
			}
		}
	}
	
}


int main(){
	Student s[100];
	int n; cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>s[i].marks>>s[i].name;
	}
	
	bucket_sort(s, n);
}
