class Solution {
public:
  int dfs(int n, int row, int l, int m, int r) {
    if (row == n)
      return 1;

    int vacancy = ~(l | m | r);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      if (vacancy & (1 << i)) {
        sum += dfs(n, row + 1,
          (l | (1 << i)) << 1,
          m | (1 << i),
          (r | (1 << i)) >> 1);
      }
    }
    return sum;
  }
  int totalNQueens(int n) {
    return dfs(n, 0, 0, 0, 0);
  }
};
