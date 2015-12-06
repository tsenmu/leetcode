class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int value = 0;
        int r = 0;
        int c = 0;
        /**
         * direction:
         *  - 0 right
         *  - 1 down
         *  - 2 left
         *  - 3 top
         */
        int direction = 0; 
        int limit = n * n;

        bool will_change_direction = false;

        while (value < limit) {
            if (!will_change_direction) {
                value++; 
                matrix[r][c] = value;
            } 
            will_change_direction = false;
            switch (direction) {
            case 0:
                if (c == n - 1) {
                    will_change_direction = true;
                } else if (matrix[r][c + 1] != 0) {
                    will_change_direction = true;
                } else {
                    c++;
                }
                break;
            case 1:    
                if (r == n - 1) {
                    will_change_direction = true;
                } else if (matrix[r + 1][c] != 0) {
                    will_change_direction = true;
                } else {
                    r++;
                }
                break;
            case 2:
                if (c == 0) {
                    will_change_direction = true;
                } else if (matrix[r][c - 1] != 0) {
                    will_change_direction = true;
                } else {
                    c--;
                }
                break;
            case 3:
                if (r == 0) {
                    will_change_direction = true;
                } else if (matrix[r - 1][c] != 0) {
                    will_change_direction = true;
                } else {
                    r--;
                }
            }
            if (will_change_direction) {
                direction = ((direction + 1) % 4);
            }
        }
        return matrix;
    }
};