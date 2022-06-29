//Given a stream of characters and we have to find first non repeating character each time a character is inserted to the stream. 
//Dot(.) means end of the stream.
//Queue is used

#include<bits/stdc++.h>
using namespace std;
int main(){
	queue<int> q;
	int freq[26]={0};
	char ch;
	cin>>ch;
	
	while(ch!='.'){
		q.push(ch);
		freq[ch-'a']++;
		
		while(!q.empty()){
			if(freq[q.front()-'a'] > 1){
				q.pop();
			}
			else{
				cout<<ch<<" ";
				break;
			}
		}
		if(q.empty()){
			cout<<"-1"<<" ";
		}
        cin>>ch;
	}
	return 0;
}
