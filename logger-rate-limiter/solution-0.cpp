class Logger {

protected:
    unordered_map<string, int> m_map;
    list<pair<int, string>> m_queue;

public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        bool ret = false;
        if (m_map.count(message) == 0) {
            m_map[message] = timestamp;
            ret = true;
        } else {
            int lastTimestamp = m_map[message];
            if (timestamp - lastTimestamp >= 10) {
                m_map[message] = timestamp;
                ret = true;
            }
        }

        m_queue.push_back(make_pair(timestamp, message));

        while (!m_queue.empty()) {
            int ts =  m_queue.front().first;
            string ms = m_queue.front().second;
            if ((timestamp - ts) >= 10) {
                if (m_map[message] == ts) {
                    m_map.erase(ms);
                }
                m_queue.pop_front();
            } else {
                break;
            }
        }

        return ret;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */