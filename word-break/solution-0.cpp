class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
      int n = s.length();
      bool isBreakable[n];
      memset(isBreakable, false, sizeof isBreakable);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
          string sub = s.substr(j, i - j + 1);
          if (wordDict.count(sub) > 0) {
            if (j > 0) {
              if (isBreakable[j - 1]) {
                isBreakable[i] = true;
              }
            } else {
              isBreakable[i] = true;
            }
          }
        }
      }
      return isBreakable[n - 1];
    }
};