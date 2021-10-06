#include<bits/stdc++.h>

using namespace std;

bool balance_para(string str) {

    stack<char> s;
    char a;

    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]== '[') {
            s.push(str[i]); //push any opening bracket to stack
            continue; //next iteration 
        }
        
        if(s.empty())
            return false;

        switch(str[i]) {
            case ')':
                a = s.top();
                s.pop();

                if(a== '{' || a== '[')
                    return false;

                break;

                
            case '}':
                a = s.top();
                s.pop();

                if(a== '(' || a== '[')
                    return false;
                    
                break;

                
            case ']':
                a = s.top();
                s.pop();

                if(a== '{' || a== '(')
                    return false;
                    
                break;
        }
    }

    return s.empty();
}

int main()
{

    string str = "([])";
    
    if(balance_para(str)) 
        cout<<"Balanced parantheses";
    else
        cout<<"Unbalanced parantheses";

    return 0;
    
}