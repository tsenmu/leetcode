class LRUCache{
protected:
    // key
    list<int> m_list;
    // key, (it, value)
    unordered_map<int, pair<list<int>::iterator, int>> m_map;
    int m_capacity;

public:
    LRUCache(int capacity) { 
        m_capacity = capacity; 
    }
    
    int get(int key) {
        if (m_map.count(key) == 0) {
            return -1;
        }
        set(key, m_map[key].second);
        return m_map[key].second;
    }
    
    void set(int key, int value) {

        if (m_map.count(key) == 0) { // if key is not in there
            // Clean the outdated cache if necessary.
            while (m_list.size() >= m_capacity) {
                m_map.erase(m_list.back());
                m_list.pop_back();
            }
        } else {
            // find the iterator in list. 
            pair<list<int>::iterator, int> p = m_map[key];
            list<int>::iterator it = p.first;
            // erase this iterator from the list.
            m_list.erase(it);
        }
        
        // push a new key to the back of the list.
        m_list.push_front(key);
        // update the iterator and the value in the hash map.
        m_map[key] = make_pair(m_list.begin(), value);
    }
};