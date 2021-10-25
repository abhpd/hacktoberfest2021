#include<bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> s,mins;
public:
    MinStack() {
        while(!s.empty()) s.pop();
        while(!mins.empty()) mins.pop();
    }
    
    void push(int val) {
        s.push(val);
        if(mins.empty()) mins.push(val);
        else
        {
            mins.push(min(mins.top(),val));
        }
    }
    
    void pop() {
        mins.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

int main()
{
  MinStack m;
  m.push(1);
  m.push(2);
  cout<<m.getMin()<<'\n';
  cout<<m.top()<<'\n';
  m.pop();
  m.pop();
  return 0;
}
