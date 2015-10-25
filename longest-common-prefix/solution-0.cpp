class Solution {
public:
  string getCommonPrefix(const string& a, const string& b) {
    string prefix; 
    for (int i = 0; i < min(a.length(), b.length()); ++i) {
      if (a[i] == b[i]) {
        prefix.push_back(a[i]);
      } else {
        return prefix;
      }
    }
  }
  string longestCommonPrefix(vector<string>& strs) {
    string ans;      
    if (strs.size() == 0) {
      return ans;
    }
    ans = strs[0];
    for (int i = 1; i < strs.size(); ++i) {
      string& s = strs[i];
      ans = getCommonPrefix(ans, s);
    }
    return ans;
  }
};