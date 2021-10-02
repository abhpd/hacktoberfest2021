
#include <bits/stdc++.h>
using namespace std;
string rW(string str)
{
	stack<char> s;
    string s1="";
	for (int i = 0; i < str.length(); ++i) {
        
		if (str[i] != ' ')
			s.push(str[i]);
		else {
			while (!(s.empty())) {
				s1+=s.top();
				s.pop();
			}
			s1+=" ";
		}
	}
	while (!(s.empty())) {
		s1+=s.top();
		s.pop();
	}
    return s1;
}

int main()
{
	cout<<"Enter String    ";
    string str;
    getline(cin,str);
	cout<<"Reversed String is\n";
    cout<<rW(str);
	return 0;
}
