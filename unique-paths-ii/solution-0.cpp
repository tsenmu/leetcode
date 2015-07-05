class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.size() == 0) {
      return 0;
    }
    const int row = obstacleGrid.size();
    const int col = obstacleGrid[0].size();
    int dp[col];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        const int& v = obstacleGrid[i][j]; 
        int& dpEntry = dp[j];
        const int& dpPrevious = i == 0 ? (j == 0 ? 1 : dp[j - 1]) : (j == 0 ? 0 : dp[j - 1]);
        if (v) {
          dpEntry = 0;
        } else {
          dpEntry = dpPrevious + dpEntry;
        }
      }
    }
    return dp[col - 1];
  }
};