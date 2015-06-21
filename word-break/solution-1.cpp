class Solution {
public:
  bool wordBreak(string s, unordered_set<string>& wordDict) {
    s = " " + s;
    int n = s.length() + 1;
    bool ok[n];
    memset(ok, false, sizeof ok);
    ok[0] = true;
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j <= i; ++j) {
        if (ok[j - 1] && wordDict.count(s.substr(j, i - j + 1))) {
          ok[i] = true;
          break;
        }
      }
    }
    return ok[n - 1];
  }
};