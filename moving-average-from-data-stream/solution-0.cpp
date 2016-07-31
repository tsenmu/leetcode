class MovingAverage {
protected:
    list<int> m_list;
    int m_sum;
    int m_size;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        m_size = size;
        m_sum = 0;
    }
    
    double next(int val) {
        m_list.push_back(val);
        m_sum += val;
        if (m_list.size() > m_size) {
            m_sum -= m_list.front();
            m_list.pop_front();
        }
        return 1.0 * m_sum / m_list.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */