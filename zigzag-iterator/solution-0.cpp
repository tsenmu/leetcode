class ZigzagIterator {
protected:
    vector<vector<int>> m_vectors; 
    int m_maxVectorLength;
    int m_currentIndex;
    int m_currentVector;
    void seekNextAvailablePosition() {
        if (m_currentIndex == -1 || m_currentVector == -1) {
            return;
        }

        // initialize next possible position
        m_currentVector++;
        if (m_currentVector == m_vectors.size()) {
            m_currentVector = 0;
            m_currentIndex++;
        }

        // validate next possible position and iterate subsequent 
        // possible positions if the current one is not valid
        bool found = false;
        while (m_currentIndex < m_maxVectorLength) {
            while (m_currentVector < m_vectors.size()) {
                if (m_currentIndex < m_vectors[m_currentVector].size()) {
                    found = true;
                    break;
                }
                m_currentVector++;
            }
            if (found) {
                break;
            }
            m_currentVector = 0;
            m_currentIndex++;
        }

        if (m_currentIndex == m_maxVectorLength) {
            m_currentVector = -1;
            m_currentIndex = -1;
        }
    }

    void findMaxVectorLength() {
        m_maxVectorLength = 0;
        for (int i = 0; i < m_vectors.size(); ++i) {
            m_maxVectorLength = max(m_maxVectorLength, (int) m_vectors[i].size());
        }
    }

    void findFirstValidPosition() {
        m_currentIndex = 0;
        m_currentVector = 0;
        for (int i = 0; i < m_vectors.size(); ++i) {
            if (m_vectors[i].size() > 0) {
                break;
            } 
            m_currentVector++;
        }

        if (m_currentVector == m_vectors.size()) {
            m_currentIndex = -1; 
            m_currentVector = -1;
        } 
    }

public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        m_vectors.clear();
        m_vectors.push_back(v1);
        m_vectors.push_back(v2);
        findFirstValidPosition();
        findMaxVectorLength();
    }

    int next() {
        assert(m_currentVector != -1 && m_currentVector != -1); 
        int ret = m_vectors[m_currentVector][m_currentIndex];
        seekNextAvailablePosition();
        return ret;
    }

    bool hasNext() {
        return m_currentIndex != -1 && m_currentVector != -1;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */