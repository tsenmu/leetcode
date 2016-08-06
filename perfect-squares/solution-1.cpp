class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {

            int ans = INT_MAX; 
            for (int j = 1; j * j <= i; ++j) {
                ans = min(ans, dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};