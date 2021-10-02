#include <bits/stdc++.h>
using namespace std;

struct Stack_Using_vec{
    vector<int> v;
    
    void push(int x){
        v.push_back(x);
    }

    int size(){
        return v.size();
    }
    
    int pop(){
        int res=v.back();
        v.pop_back();
        return res;
    }
    
    bool isEmpty(){
        return v.empty();
    }

    int peek(){
        return v.back();
    }
    
};

int main()
{
    Stack_Using_vec s;
    s.push(14);
    s.push(10);
    s.push(8);
    s.push(9);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
  
    return 0; 
}
