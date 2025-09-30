class MinStack {
private:
    stack<int> stIn;
    stack<int> stOut;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stIn.push(val);
        if(stOut.empty()||val<=stOut.top())stOut.push(val);
    }
    
    void pop() {
        if(stIn.top()==stOut.top()) stOut.pop();
        stIn.pop();
    }
    
    int top() {
        return stIn.top();
    }
    
    int getMin() {
        return stOut.top();
    }
};

/*
需要有一個正常的 stack stIn 儲存所有值，再加上一個輔助的stack stOut，用來儲存當前的最小值。
push: 如果stOut 為空(沒有最小值)，或是 val < stOut.top()(當前最小值)
就把這個值傳進stOut 中
pop: 如果當前要 pop 的元素相等，stOut也要一起pop(更新最小值)，stIn.pop()
top: 回傳目前 stIn.top()
getMIn: 回傳目前儲存的最小值 stOut.top()
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */