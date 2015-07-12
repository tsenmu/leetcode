class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    if (grid.size() == 0) {
      return 0;
    }
    int r = grid.size();
    int c = grid[0].size();
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        int candidate_min = INT_MAX;
        if (i - 1 >= 0) {
          candidate_min = min(candidate_min, grid[i][j] + grid[i - 1][j]);
        }
        if (j - 1 >= 0) {
          candidate_min = min(candidate_min, grid[i][j] + grid[i][j - 1]);
        }
        if (i == 0 && j == 0) {
          candidate_min = grid[i][j];
        }
        grid[i][j] = candidate_min;
      }
    }
    return grid[r - 1][c - 1];
  }
};