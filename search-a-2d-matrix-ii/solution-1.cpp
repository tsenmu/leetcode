class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        int row = 0;
        int col = (int)matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0) {
            int cur = matrix[row][col];
            if (cur == target) {
                return true;
            } else if (cur > target) {
                col--; 
            } else {
                row++;
            }
        }

        return false;
    }
};