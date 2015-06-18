class Solution {
public:
  int maximalSquare(vector<vector<char> >& matrix) {
    vector<vector<int> > dp;
    int max_val = 0;
    for (int i = 0; i < matrix.size(); ++i) {
      dp.push_back(vector<int>());
      vector<int>& dp_row = dp[dp.size() - 1];
      for (int j = 0; j < matrix[i].size(); ++j) {
        int v = (int)(matrix[i][j] == '1');
        if (i > 0 && j > 0) {
          if (v) {
            v = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
          } else {
            v = 0;
          }
        }
        max_val = max(v, max_val);
        dp_row.push_back(v);
      }
    }
    return max_val * max_val;
  }
};