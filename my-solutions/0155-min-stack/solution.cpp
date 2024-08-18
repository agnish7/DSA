class MinStack {
    stack<int> numStack;
    stack<int> minNumStack;
    int minNum;
public:
    MinStack() {
        minNum = INT_MAX;
    }
    
    void push(int val) {
        this->numStack.push(val);
        this->minNum = min(this->minNum, val);
        minNumStack.push(this->minNum);
    }
    
    void pop() {
        this->numStack.pop();
        this->minNumStack.pop();
        this->minNum = minNumStack.empty() ? INT_MAX : minNumStack.top();
    }
    
    int top() {
        return this->numStack.top();
    }
    
    int getMin() {
        return this->minNumStack.top();
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
