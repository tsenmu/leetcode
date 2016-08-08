class PhoneDirectory {
protected:
    vector<int> m_list;
    vector<bool> m_taken;
    int m_top;
    int m_maxNumbers;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        m_maxNumbers = maxNumbers;
        m_list = vector<int>(maxNumbers, 0);
        m_taken = vector<bool>(maxNumbers, false);
        m_top = m_maxNumbers - 1;
        
        for (int i = 0; i < maxNumbers; ++i) {
            m_list[i] = i;
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (m_top == -1) {
            return -1;
        }
        m_taken[m_list[m_top]] = true;
        return m_list[m_top--];
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (number < 0 && number >= m_maxNumbers) {
            return false;
        }
        return !m_taken[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number < 0 && number >= m_maxNumbers) {
            return;
        }
        if (m_taken[number]) {
            m_taken[number] = false;
            m_list[++m_top] = number;
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */