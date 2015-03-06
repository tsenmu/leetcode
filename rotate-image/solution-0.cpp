class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
      int n = matrix.size();
      int n_half = n >> 1;
      for (int i = 0; i < n_half; ++i) {
        for (int j = 0; j < n_half; ++j) {
          swap(matrix[i][j], matrix[n - i - 1][j]);
        }
      }        
      for (int i = 0; i < n_half; ++i) {
        for (int j = 0; j < n_half; ++j) {
          swap(matrix[i][j], matrix[j][i]);
        }
      }  
    }
};