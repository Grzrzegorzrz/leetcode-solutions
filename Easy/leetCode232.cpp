class MyQueue {
public:
    stack<int> inStack, queueStack;

    MyQueue() {

    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if(queueStack.empty()) {
            while(!inStack.empty()) {
                queueStack.push(inStack.top());
                inStack.pop();
            }
        } 
        
        int out = queueStack.top();
        queueStack.pop();

        return out;
    }

    int peek() {
        if(queueStack.empty()) {
            while(!inStack.empty()) {
                queueStack.push(inStack.top());
                inStack.pop();
            }
        } 

        return queueStack.top();
    }

    bool empty() {
        if(!inStack.empty() || !queueStack.empty())
            return false;
        return true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
