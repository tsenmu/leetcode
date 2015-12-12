class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int half_n = (n >> 1);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        } 

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < half_n; ++j) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};