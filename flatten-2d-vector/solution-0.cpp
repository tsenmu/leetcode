class Vector2D {
protected: 
    int m_row = -1; 
    int m_col = -1;
    vector<vector<int>> m_vec;
    void seekNext() {
        m_col++;
        while (m_row < m_vec.size()) {
            if (m_col == m_vec[m_row].size()) {
                m_col = 0;
                m_row++;
            } else {
                return;
            }
        } 

        if (m_row == m_vec.size()) {
            m_row = m_col = -1;
        }
    }
public:
    Vector2D(vector<vector<int>>& vec2d) {
        m_vec = vec2d; 
        if (m_vec.size() != 0) {
            m_row = 0;
            m_col = -1;
            seekNext();
        }
    }

    int next() {
        int val = m_vec[m_row][m_col];
        seekNext();
        return val;
    }

    bool hasNext() {
        return m_row != -1 && m_col != -1;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */