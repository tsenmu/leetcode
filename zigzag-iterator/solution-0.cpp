class ZigzagIterator {
protected:
    list<vector<int>> m_vectors;
    list<vector<int>>::iterator it;
    int column;

public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) {
            m_vectors.push_back(v1);
        }
        if (!v2.empty()) {
            m_vectors.push_back(v2);
        }
        it = m_vectors.begin();
        column = 0;
    }

    int next() {
        int ret = -1;
        vector<int>& vec = *it;
        ret = vec[column];
        if (column == vec.size() - 1) {
            it = m_vectors.erase(it); 
        } else {
            ++it;
        }
        if (it == m_vectors.end()) {
            if (!m_vectors.empty()) {
                it = m_vectors.begin();
                column++;
            }
        }
        return ret;
    }

    bool hasNext() {
        return !m_vectors.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */