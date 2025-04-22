class MyQueue {
public:
    stack<int> stackIn;
    stack<int> stackOut;
    MyQueue() {
        
    }
    
    void push(int x) {
        stackIn.push(x);
    }
    
    int pop() {
        int result;
        if(stackOut.empty()){ //檢查 stackOut 是否為空
            while(!stackIn.empty()){
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        result=stackOut.top();
        stackOut.pop();
        return result;
    }
    
    int peek() {
        int result;
        result=this->pop(); //調用本次的 pop 函數
        stackOut.push(result);
        return result;
    }
    
    bool empty() {
        return stackIn.empty() && stackOut.empty();
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