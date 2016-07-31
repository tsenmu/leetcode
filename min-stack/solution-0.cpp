class MinStack {
protected:
    stack<int> m_list;
    stack<int> m_min;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        m_list.push(x);
        m_min.push(m_min.empty() ? x : min(m_min.top(), x));
    }
    
    void pop() {
        m_list.pop();
        m_min.pop();
    }
    
    int top() {
        return m_list.top();
    }
    
    int getMin() {
        return m_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */