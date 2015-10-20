class Stack {
public:
    queue<int> q;

    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        size_t qs = q.size();
        for (int i = 0; i < qs - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }

    // Get the top element.
    int top() {
        size_t qs = q.size();
        for (int i = 0; i < qs - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.push(q.front());
        q.pop();
        return ans;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};