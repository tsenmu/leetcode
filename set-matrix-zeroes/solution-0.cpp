class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
      int r = matrix.size();
      int c = 0;
      if (r > 0) {
        c = matrix[0].size();
      }
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          if (matrix[i][j] == 0) {
            for (int k = 0; k < r; ++k) {
              if (matrix[k][j] == 0) {
                matrix[k][j] = -INT_MAX;
              }
            }
          }
        }
      }
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          if (matrix[i][j] == -INT_MAX) {
            matrix[i][j] = 0;
          }
        }
      }
    }
};