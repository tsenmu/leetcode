class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = 0;
        vector<bool> col_reg;

        if (row == 0) {
            return; 
        }

        col = matrix[0].size();
        col_reg.resize(col, false);

        for (int i = 0; i < row; ++i) {
            bool has_zero = false;
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    col_reg[j] = true;
                    has_zero = true;
                }
            }
            if (has_zero) {
                matrix[i].assign(col, 0);
            }
        }

        for (int j = 0; j < col; ++j) {
            if (col_reg[j]) {
                for (int i = 0; i < row; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};