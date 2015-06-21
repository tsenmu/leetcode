class Solution {
private: 
  vector<string> ans;
  vector<vector<int> > startingIndices;
  void buildStartingIndices(string s, unordered_set<string>& wordDict) {
    int n = s.length();
    for (int i = 0; i < n; ++i) {
      startingIndices.push_back(vector<int>());
    }
    startingIndices[0].push_back(-1);
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j <= i; ++j) {
        if (startingIndices[j - 1].size() != 0 && wordDict.count(s.substr(j, i - j + 1))) {
          startingIndices[i].push_back(j);
        }
      }
    }
    return;
  }

  void dfs(string& s, int index, string suffix) {
    if (index == 0) {
      ans.push_back(suffix);
      return;
    }
    for (int i = 0; i < startingIndices[index].size(); ++i) {
      int start = startingIndices[index][i];
      string sub = s.substr(start, index - start + 1);
      string new_suffix;
      if (suffix.length() == 0) {
        new_suffix = sub;
      } else {
        new_suffix = sub + " " + suffix;
      }
      dfs(s, start - 1, new_suffix);
    }
  }

public:
  vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    s = " " + s;
    buildStartingIndices(s, wordDict);
    dfs(s, s.length() - 1, "");
    return ans;
  }
};