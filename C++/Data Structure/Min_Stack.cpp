class MinStack {
    vector<int>stack;
     vector<int>min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        int current_min = x;
        
        if(min_stack.size()){
            current_min = min(min_stack[min_stack.size()-1],x);
            
        }
        min_stack.push_back(current_min);
        stack.push_back(x);
    }
    
    void pop() {
        min_stack.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return stack [stack.size()-1];
    }
    
    int getMin() {
        return min_stack[min_stack.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
