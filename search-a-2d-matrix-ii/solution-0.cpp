// Time Limit Exceeded
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        const int n = matrix.size();
        const int m = matrix[0].size();

        vector<int> col_index = matrix[0];
        vector<int> row_index = getCol(matrix, 0);

        int col = -1;
        int row = -1;
        col = binarySearchNotGreater(col_index, target);
        if (col != -1) {
            row = binarySearchNotGreater(getCol(matrix, col), target);
            if (row != -1 && matrix[row][col] == target) {
                return true;
            }
        }

        row = binarySearchNotGreater(row_index, target);
        if (row != -1) {
            col = binarySearchNotGreater(matrix[row], target);
            if (col != -1 && matrix[row][col] == target) {
                return true;
            }
        }
        
        return false;
    }

protected:
    int binarySearchNotGreater(const vector<int>& vec, const int target) {
        int l = 0;
        int r = (int)(vec.size()) - 1;
        int m = 0;
        // [0, 1] -1 

        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (vec[m] == target) {
                return m;
            } else if (vec[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        if (vec[r] <= target) {
            return -1;
        } else {
            return r;
        }

    }

    vector<int> getCol(vector<vector<int>>& matrix, int col) {
        vector<int> ans; 
        for (int i = 0; i < matrix.size(); ++i) {
            ans.push_back(matrix[i][col]);
        }
        return ans;
    }
};