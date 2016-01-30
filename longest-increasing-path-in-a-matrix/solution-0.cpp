class Solution {
public:


    bool isValid(int row, int col, int r, int c) const  {
        return r >= 0 && c >= 0 && r < row && c < col;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int r, int c) {
        const int row = matrix.size();
        const int col = matrix[0].size();

        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        static int directions[4][2] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        for (int i = 0; i < 4; ++i) {
            int nr = directions[i][0] + r;
            int nc = directions[i][1] + c;

            if (isValid(row, col, nr, nc) && matrix[nr][nc] > matrix[r][c]) {
                dp[r][c] = max(dfs(matrix, dp, nr, nc) + 1, dp[r][c]);
            }
        }
        
        if (dp[r][c] == -1) {
            dp[r][c] = 1;
        }
        return dp[r][c];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int row = matrix.size();
        if (row == 0) {
            return 0;
        }
        const int col = matrix[0].size();

        vector<vector<int>> dp(row, vector<int>(col, -1));

        int ans = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                ans = max(dfs(matrix, dp, i, j), ans);
            }
        }
        return ans;
    }
};