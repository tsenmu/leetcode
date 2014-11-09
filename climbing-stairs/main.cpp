class Solution {
public:
  map<int,int> dp;
  int climbStairs(int n) {
    if (!dp.count(1))
      dp[1] = 1;
    if (!dp.count(2))
      dp[2] = 2;
    if (dp.count(n))
      return dp[n];
    return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
  }
};
