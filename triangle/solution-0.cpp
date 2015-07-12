class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.size() == 0) {
      return 0;
    }
    int dp[triangle.size()];    
    memset(dp, 0, sizeof dp);
    dp[0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); ++i) {
      dp[i] = dp[i - 1] + triangle[i][i];
      for (int j = i - 1; j > 0; --j) {
        dp[j] = min(dp[j] + triangle[i][j], dp[j - 1] + triangle[i][j]);
      }
      dp[0] = dp[0] + triangle[i][0];
    }
    int ans = dp[0];
    for (int i = 1; i < triangle.size(); ++i) {
      ans = min(ans, dp[i]);
    }
    return ans;
  }
};