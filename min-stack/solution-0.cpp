class MinStack {
protected:
    stack<pair<int,int>> m_s;
public:
    void push(int x) {
        if (m_s.empty()) {
            m_s.push(make_pair(x, x));
        } else {
            m_s.push(make_pair(x, min(getMin(), x)));
        }
    }

    void pop() {
        if (!m_s.empty()) {
            m_s.pop();
        }
    }

    int top() {
        return m_s.top().first;
    }

    int getMin() {
        if (m_s.empty()) {
            return INT_MIN;
        } else {
            return m_s.top().second;
        }
    }
};