class Solution {
public:
    bool isMatch(string s, string p) {
        const int n = s.length();
        const int m = p.length();
        vector<vector<bool>> dp(n + 1, vector<int>(m + 1, false));
        
        dp[0][0] = true;

        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            for (int j = 0; j < m; ++j) {
                char pattern = p[j];
                dp[i + 1][j + 1] = dp[i][j];

                for (int k = 0; k < j; ++k) {
                    dp[i + 1][j + 1] =  
                }

            }
        }

        return dp[n][m];
    }
};