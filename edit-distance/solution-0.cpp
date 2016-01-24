class Solution {
public:
    int minDistance(string word1, string word2) {
        const int n = word1.length();
        const int m = word2.length();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        
        if (n == 0) {
            return m;
        } 
        if (m == 0) {
            return n;
        }

        for (int i = 0; i < n; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i < m; ++i) {
            dp[0][i] = i;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = min(dp[i - 1][j] + 1, 
                    min(dp[i][j - 1] + 1, 
                        dp[i - 1][j - 1] + (word1[i] == word2[j] ? 0 : 1)
                        ));
            }
        }

        return dp[n - 1][m - 1];

    }
};