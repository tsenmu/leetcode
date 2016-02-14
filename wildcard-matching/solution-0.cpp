class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= m; ++i) {
            char pattern = p[i - 1];
            if (pattern == '*') {
                for (int j = 0; j <= n; ++j) {
                    if (dp[j][i - 1]) {
                        for (int k = j; k <= n; ++k) {
                            dp[k][i] = true; 
                        }
                    }
                }
            } else if (pattern == '?') {
                for (int j = 0; j < n; ++j) {
                    if (dp[j][i - 1]) {
                        dp[j + 1][i]  = true;
                    }
                }
            } else {
                for (int j = 0; j < n; ++j) {
                    if (dp[j][i - 1] && s[j] == pattern) {
                        dp[j + 1][i] = true;
                    }
                }
            }
            
            // for (int ii = 0; ii <= n; ++ii) {
            //     for (int jj = 0; jj <= m; ++jj) {
            //         printf("%d ", dp[ii][jj] ? 1 : 0);
            //     }
            //     printf("\n");
            // }
            // printf("\n");
        }

        return dp[n][m];
    }
};