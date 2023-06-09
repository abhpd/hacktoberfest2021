/* Given a non-negative integer n representing the total number of bits in the code,
 print the sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
*/

#include<bits/stdc++.h>
using namespace std;

void checkitout(vector<int>&v,int p,int i){
	if(i==p){
		return;
	}
	
	int power=i/2;
	v.push_back(i^power);
	checkitout(v,p,i+1);
	
	
}

int main(){
	int n;
	cout<<"Enter value of n ";
	cin>>n;
	int p=pow(2,n); // this will tell the number of elements that have n number of bits.
	vector<int>v;
	checkitout(v,p,0); // call funtion checkitout
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
}
