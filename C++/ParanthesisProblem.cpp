class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        // using stack to solve this problem helps us to respect the relative placement of brackets
        
        for(int i=0;i<s.length();i++) {
            char top = st.empty() ? '#' : st.top();
            
            if(top == '(' && s[i] == ')') {
                st.pop();
            }else if(top == '{' && s[i] == '}') {
                st.pop();
            }else if(top == '[' && s[i] == ']') {
                st.pop();
            }else{
                st.push(s[i]);
            }    
        }
        
        return st.empty();
    }
};
