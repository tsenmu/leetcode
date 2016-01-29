class LRUCache{
protected:
    int m_capacity;
    list<int> m_list;
    unordered_map<int, pair<list<int>::iterator, int>> m_map;

    void touch(unordered_map<int, pair<list<int>::iterator, int>>::iterator it) {
        m_list.erase(it->second.first);
        m_list.push_front(it->first);
        it->second.first = m_list.begin();
    }

public:
    LRUCache(int capacity) : m_capacity(capacity) {}
    
    int get(int key) {
        auto it = m_map.find(key);

        if (it == m_map.end()) {
            return -1;
        }

        int val = it->second.second;
        touch(it);
        return val;
    }
    
    void set(int key, int value) {
        auto it = m_map.find(key);

        if (it == m_map.end()) {
            if (m_list.size() == m_capacity) {
                m_map.erase(m_list.back());
                m_list.pop_back();
            }
            m_list.push_front(key);
            m_map[key] = make_pair(m_list.begin(), value);
        } else {
            it->second.second = value;
            touch(it);
        }
    }
};