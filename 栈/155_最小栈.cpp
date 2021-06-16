//参考答案 两个栈，一个栈保存栈数据，一个辅助栈保存 每个元素 入栈时的最小值

class MinStack {
    stack<int> x_stk; //保存栈数据
    stack<int> min_stk; //维护每个元素入栈时的最小值
public:
    /** initialize your data structure here. */
    MinStack() {
        min_stk.push(INT_MAX); //没有元素入栈时存放 INT_MAX， 每个元素都小于min_stk.top()
    }
    
    void push(int val) {
        x_stk.push(val);
        min_stk.push(min(min_stk.top(), val));
    }
    
    void pop() {
        x_stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return x_stk.top();
    }
    
    int getMin() {
        return min_stk.top();
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
