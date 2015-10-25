class Solution {
public:
  vector<vector<string>> ans;
  string genString(int pos, int n) {
    string a;
    for (int i = 0; i < n; ++i) {
      if (i == pos) {
        a.push_back('Q');
      } else {
        a.push_back('.');
      }
    }
    return a;
  }
  void dfs(int level, int n, vector<string>& solution, int l, int m, int r) {
    if (level == n) {
      ans.push_back(solution);
      return;
    }
    int mask = (1 << n) - 1;
    l = (l << 1) & mask;
    r = (r >> 1) & mask;
    for (int i = 0; i < n; ++i) {
      if ( ((l | m | r) & (1 << i)) == 0) {
        solution.push_back(genString(i, n));
        int pl = l;
        int pm = m;
        int pr = r;
        l = (l | (1 << i)) & mask;
        m = (m | (1 << i)) & mask;
        r = (r | (1 << i)) & mask;
        dfs(level + 1, n, solution, l, m, r);
        solution.pop_back();
        l = pl;
        m = pm;
        r = pr;
      } 
    }
  }
  vector<vector<string>> solveNQueens(int n) {
    vector<string> solution;
    dfs(0, n, solution, 0, 0, 0);
    return ans;
  }
};