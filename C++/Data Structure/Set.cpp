#include <iostream>
#include<set>

using namespace std;

int main() {
	
	set<int>s1; //creation of set
	
	//inserting values in set s1
	s1.insert(10);
	s1.insert(45);
	s1.insert(10);  //10 will not be inserted again as set contain distinct values
	
	cout<<"Set I: \n";

	for(int i:s1)
	cout<<i<<" ";

	cout<<endl;
//-------------------------------
    set<int>s2; //creation of another set
	int n;
	cin>>n;
	int arr[n];
	//inserting array values in set s2
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	    s2.insert(arr[i]);
	}
	
	cout<<"\nSet II: \n";
    
	for(int i:s2)
	cout<<i<<" ";
	
	
	return 0;
}
