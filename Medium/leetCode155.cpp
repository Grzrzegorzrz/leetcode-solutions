class MinStack {
public:
    stack<int> stk;
    priority_queue<int, vector<int>, greater<int>> pQ;
    
    MinStack() {

    }

    void push(int val) {
        stk.push(val);
        if(pQ.empty() || val <= pQ.top()) pQ.push(val);
    }

    void pop() {
        if(stk.top() == pQ.top()) pQ.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }

    int getMin() {
        return pQ.top();
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
