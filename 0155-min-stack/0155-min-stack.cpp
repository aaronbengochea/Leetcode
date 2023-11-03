class MinStack {
public:
    stack<int> stack, minStack;
    MinStack() {}
    
    void push(int val) {
        stack.push(val);

        if(!minStack.empty()){
            val = min(val, minStack.top());
        }

        minStack.push(val);
        
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
        
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */