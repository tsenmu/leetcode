class MinStack {
public:
    stack<pair<int, int>> S;
    int minimum = INT_MAX;
    int minimum_pos = -1;
    void push(int x) {
        S.push(make_pair(x, minimum_pos))
    }

    void pop() {
        
    }

    int top() {
        return S.top().first;
    }

    int getMin() {
        return minimum; 
    }
};