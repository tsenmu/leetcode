class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp({0});
        
        while (dp.size() <= n) {
            int i = dp.size();
            int ans = INT_MAX; 
            for (int j = 1; j * j <= i; ++j) {
                ans = min(ans, dp[i - j * j] + 1);
            }
            dp.push_back(ans);
        }
        
        return dp[n];
    }
};