class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = 0;

        if (row == 0) {
            return;
        }

        col = matrix[0].size();

        bool row_zero_has_zero = false;
        for (int j = 0; j < col; ++j) {
            if (matrix[0][j] == 0) {
                row_zero_has_zero = true;
                break;
            }
        }
        
        for (int i = 1; i < row; ++i) {
            bool has_zero = false;
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    has_zero = true;
                    matrix[0][j] = 0;
                }
            }
            if (has_zero) {
                matrix[i].assign(col, 0);
            }
        }

        for (int j = 0; j < col; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < row; ++i) {
                    matirx[i][j] = 0;
                }
            }
        }

        if (row_zero_has_zero) {
            matrix[0].assign(col, 0);
        }
    }
};