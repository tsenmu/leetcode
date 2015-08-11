class Solution {
public:
  void expand(int** grid, 
    bool** visited, const int row, const int col, int x, int y) {
    queue<pair<int, int>> Q;
    Q.push(make_pair(x, y));
    while (!Q.empty()) {
      x = Q.front().first; 
      y = Q.front().second;

      if (grid[x][y] == 1 && !visited[x][y]) {
        Q.push(make_pair(x - 1, y));
        Q.push(make_pair(x + 1, y));
        Q.push(make_pair(x, y + 1));
        Q.push(make_pair(x, y - 1));
      }
      visited[x][y] = true;

      Q.pop();
    }
  }
  int numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0) {
      return 0;
    }      
    int row = grid.size();
    int col = grid[0].size();
    int augmentedGrid[row + 2][col + 2];
    memset(augmentedGrid, 0, sizeof augmentedGrid);
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        augmentedGrid[i + 1][j + 1] = grid[i][j] == '1' ? 1 : 0;
      }
    }
    row = row + 2;
    col = col + 2;
    bool visited[row][col];
    memset(visited, false, sizeof visited);
    int ans = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (!visited[i][j] && augmentedGrid[i][j] == 1) {
          ++ans;
          expand((int**)augmentedGrid, (bool**)visited, row, col, i, j);
        }
      }
    }
    return ans;
  }
};