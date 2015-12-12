class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        int n = prices.size();

        int dp[3][n];

        memset(dp, 0, sizeof dp);

        dp[1][1] = max(prices[1] - prices[0], 0);

        for (int i = 2; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[1][i] = max(dp[1][i], dp[0][j] + prices[i] - prices[j]);
            }
            for (int j = 1; j < i; ++j) {
                dp[2][i] = max(dp[2][i], dp[1][j] + prices[i] - prices[j]);
            }
        }

        return max(max(dp[1][n - 1], dp[2][n - 1]), dp[0][n - 1]);
    }
};