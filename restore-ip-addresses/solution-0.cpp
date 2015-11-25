class Solution {
public:
  vector<vector<int>> results;

  void dfs(vector<int>& result, string& s) {
    if (result.size() == 3) {
      string numStr = s.substr(result[2]);
      if (isValid(numStr)) {
        results.push_back(result);
      }
      return;
    } 
    int lastPosition = result.size() == 0 ? 0 : result[result.size() - 1];
    for (int i = 1; i <= 3 && lastPosition + i < s.length(); ++i) {
      string numStr = s.substr(lastPosition, i);
      if (isValid(numStr)) {
        result.push_back(lastPosition + i);
        dfs(result, s);
        result.pop_back();
      }
    }
  }

  bool isValid(string& s) {
    if (hasLeadingZeros(s)) {
      return false;
    }
    int num = toInt(s);
    if (num >= 0 && num <= 255) {
      return true;
    } 
    return false;
  }

  bool hasLeadingZeros(string& s) {
    if (s.length() > 1 && s[0] == '0') {
      return true;
    } 
  }

  int toInt(string& s) {
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
      ans *= 10;
      ans += (s[i] - '0');
    } 
    return ans;
  }

  vector<string> restoreIpAddresses(string s) {
    vector<int> result;       
    dfs(result, s);

    vector<string> ans;
    for (int i = 0; i < results.size(); ++i) {
      string str;
      for (int j = 0; j < 3; ++j) {
        str += s.substr(j == 0 ? 0 : results[i][j - 1], 
          j == 0 ? results[i][j] : results[i][j] - results[i][j - 1]);
        str += ".";
      }
      str += s.substr(results[i][2]);
      ans.push_back(str);
    } 
    return ans;
  }
};