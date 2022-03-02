// C++ code to reverse a
// stack using recursion
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 

stack<char> st;
 

string ns;
 

char insert_at_bottom(char x)
{
 
    if(st.size() == 0)
    st.push(x);
 
    else
    {
         
        
        char a = st.top();
        st.pop();
        insert_at_bottom(x);
 
       
        st.push(a);
    }
}
 
)
char reverse()
{
    if(st.size()>0)
    {
         
        
        char x = st.top();
        st.pop();
        reverse();
         
       
        insert_at_bottom(x);
    }
}
 
// Driver Code
int main()
{
     
    // push elements into
    // the stack
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
     
    cout<<"Original Stack"<<endl;
     
    
    cout<<"1"<<" "<<"2"<<" "
        <<"3"<<" "<<"4"
        <<endl;
     
    
    reverse();
    cout<<"Reversed Stack"
        <<endl;
     
   
    while(!st.empty())
    {
        char p=st.top();
        st.pop();
        ns+=p;
    }
     
 
    cout<<ns[3]<<" "<<ns[2]<<" "
        <<ns[1]<<" "<<ns[0]<<endl;
    return 0;
}
 
