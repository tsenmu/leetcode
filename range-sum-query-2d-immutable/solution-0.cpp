class NumMatrix {
protected:
    vector<vector<int>> matrix;
    vector<vector<int>> sum;
    int row;
    int col;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        this->matrix = matrix;

        row = matrix.size();
        if (row == 0) {
            return;
        }
        col = matrix[0].size();
        if (col == 0) {
            return;
        }
        sum = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row == 0 || col == 0) {
            return 0;
        }
        if (row1 >= row) row1 = row - 1;
        if (row1 < 0) row1 = 0;
        if (row2 >= row) row2 = row - 1;
        if (row2 < 0) row2 = 0;
        if (col1 >= col) col1 = col - 1;
        if (col1 < 0) col1 = 0;
        if (col2 >= col) col2 = col - 1;
        if (col2 < 0) col2 = 0;
        return sum[row2 + 1][col2 + 1] + sum[row1][col1] - sum[row2 + 1][col1] - sum[row1][col2 + 1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);