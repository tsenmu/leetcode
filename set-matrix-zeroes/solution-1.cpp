class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = 0;

        vector<bool> reg_row(row, false);

        if (row == 0) {
            return;
        }

        col = matrix[0].size();

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    reg_row[i] = true;
                    break;
                }
            }
        }

        for (int j = 0; j < col; ++j) {
            for (int i = 0; i < row; ++i) {
                if (matrix[i][j] == 0) {
                   for (int ii = 0; ii < row; ++ii)  {
                        matrix[ii][j] = 0;
                   }
                   break;
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            if (reg_row[i]) {
                for (int j = 0; j < col; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};