class Solution {
public:
    int maxCoins(vector<int>& input) {
        int n = input.size();
        vector<int> nums(n + 2, 0);
        for (int i = 0; i < n; ++i) {
            nums[i + 1] = input[i];
        }
        nums[0] = nums[n + 1] = 1;
        n += 2;

        int dp[n][n];
        memset(dp, 0, sizeof dp);

        for (int k = 2; k < n; ++k) {
            for (int left = 0; left < n - k; ++left) {
                int right = left + k;
                for (int i = left + 1; i < right; ++i) {
                    dp[left][right] = max(dp[left][right], 
                        dp[left][i] + dp[i][right] + nums[left] * nums[i] * nums[right]);
                }
            }
        }

        return dp[0][n - 1];
    }
};