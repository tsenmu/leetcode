class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int dp[nums.size()][2];
    memset(dp, 0, sizeof dp);
    dp[0][1] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      int v = nums[i];
      if (i == nums.size() - 1) {
        dp[i][0] = dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]);
      } else {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        dp[i][1] = dp[i - 1][0] + v;
      }
    }
    int ans = max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    memset(dp, 0, sizeof dp);
    for (int i = 1; i < nums.size(); ++i) {
      int v = nums[i];
      dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
      dp[i][1] = dp[i - 1][0] + v;
    }
    ans = max(ans, max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]));
    return ans;
  }
};