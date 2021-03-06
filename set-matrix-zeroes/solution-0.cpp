class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();        
        int col = 0;
        vector<bool> regs_row(row, false);
        vector<bool> regs_col;

        if (row == 0) {
            return;
        }

        col = matrix[0].size();
        regs_col.resize(col, false);

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    regs_row[i] = true;
                    regs_col[j] = true;
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            if (regs_row[i]) {
                for (int j = 0; j < col; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < col; ++j) {
            if (regs_col[j]) {
                for (int i = 0; i < row; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};