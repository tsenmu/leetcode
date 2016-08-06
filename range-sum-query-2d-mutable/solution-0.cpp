class NumMatrix {
protected:
    int m_row;
    int m_col;
    vector<vector<int>> m_tree;

    int update(int rowRt, int colRt,
        int rowLeft, int rowRight,
        int colLeft, int colRight,
        int row, int col, int val) {

        if (rowLeft == rowRight && colLeft == colRight) {
            int diff = val - m_tree[rowRt][colRt];
            m_tree[rowRt][colRt] = val;
            return diff;
        }

        int rowMid = rowLeft + ((rowRight - rowLeft) >> 1);
        int colMid = colLeft + ((colRight - colLeft) >> 1);

        int ret = 0;

        if (row <= rowMid) {
            if (col <= colMid) {
                ret = update(rowRt << 1, colRt << 1, rowLeft, rowMid, colLeft, colMid, row, col, val);
            } else {
                ret = update(rowRt << 1, colRt << 1 | 1, rowLeft, rowMid, colMid + 1, colRight, row, col, val);
            }
        } else {
            if (col <= colMid) {
                ret = update(rowRt << 1 | 1, colRt << 1, rowMid + 1, rowRight, colLeft, colMid, row, col, val);
            } else {
                ret = update(rowRt << 1 | 1, colRt <<  1 | 1, rowMid + 1, rowRight, colMid + 1, colRight, row, col, val);
            }
        }
        m_tree[rowRt][colRt] += ret;
        return ret;
    }

    int sumRegion(int rowRt, int colRt, 
        int rowLeft, int rowRight, 
        int colLeft, int colRight,
        int row1, int col1, int row2, int col2) {

        if (max(rowLeft, row1) > min(rowRight, row2) || max(colLeft, col1) > min(colRight, col2)) {
            return 0; 
        }

        int rowMid = rowLeft + ((rowRight - rowLeft) >> 1);
        int colMid = colLeft + ((colRight - colLeft) >> 1);

        int ans = 0;

        if (row1 <= rowLeft && rowRight <= row2 && col1 <= colLeft && colRight <= col2)  {
            ans += m_tree[rowRt][colRt];
            return ans;
        }

        ans += sumRegion(rowRt << 1, colRt << 1, rowLeft, rowMid, colLeft, colMid, row1, col1, row2, col2);
        ans += sumRegion(rowRt << 1, colRt << 1 | 1, rowLeft, rowMid, colMid + 1, colRight, row1, col1, row2, col2);
        ans += sumRegion(rowRt << 1 | 1, colRt << 1, rowMid + 1, rowRight, colLeft, colMid, row1, col1, row2, col2);
        ans += sumRegion(rowRt << 1 | 1, colRt <<  1 | 1, rowMid + 1, rowRight, colMid + 1, colRight, row1, col1, row2, col2);
        return ans;
    }

public:
    NumMatrix(vector<vector<int>> &matrix) {
        m_row = matrix.size();
        
        if (m_row == 0) {
            return;    
        }
        
        m_col = matrix[0].size();
        m_tree = vector<vector<int>>(max(m_row, m_col) << 3, vector<int>(max(m_row, m_col) << 3, 0));

        for (int i = 0; i < m_row; ++i) {
            for (int j = 0; j < m_col; ++j) {
                update(1, 1, 0, m_row - 1, 0, m_col - 1, i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        if (m_tree.size() == 0) {
            return;
        }
        update(1, 1, 0, m_row - 1, 0, m_col - 1, row, col, val);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m_tree.size() == 0) {
            return 0;
        }
        return sumRegion(1, 1, 0, m_row - 1, 0, m_col - 1, row1, col1, row2, col2);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);