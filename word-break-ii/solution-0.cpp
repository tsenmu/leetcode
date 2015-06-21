class Solution {
private: 
  vector<string> ans;
  void dfs(string& s, unordered_set<string>& wordDict, int start, int n, string result) {
    if (start == n) {
      ans.push_back(result);
      return;
    }
    for (int end = start; end < n; ++end) {
      string sub = s.substr(start, end - start + 1);
      if (wordDict.count(sub)) {
        string new_result = "";
        if (result.length() == 0) {
          new_result = sub;
        } else {
          new_result = result + " " + sub;
        }
        dfs(s, wordDict, end + 1, n, new_result);
      }
    }
  }
  bool isBreakable(string s, unordered_set<string>& wordDict) {
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
public:
  vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    if (!isBreakable(s, wordDict)) {
      return ans;
    }
    dfs(s, wordDict, 0, s.length(), "");
    return ans;
  }
};