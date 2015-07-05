class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.size() == 0) {
      return 0;
    }
    const int& row = obstacleGrid.size(); 
    const int& col = obstacleGrid[0].size();
    bool obstacleFound = false;
    for (int i = 0; i < col; ++i) {
      if (obstacleFound) {
        obstacleGrid[0][i] = 0;
        continue;
      }
      if (obstacleGrid[0][i]) {
        obstacleGrid[0][i] = 0;
        obstacleFound = true;
      } else {
        obstacleGrid[0][i] = 1;
      }
    }
    for (int i = 1; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (obstacleGrid[i][j]) {
          obstacleGrid[i][j] = 0;
        } else {
          obstacleGrid[i][j] = ( j == 0 ? 0 : obstacleGrid[i][j - 1] ) + obstacleGrid[i - 1][j];
        }
      }
    }
    return obstacleGrid[row - 1][col - 1];
  }
};