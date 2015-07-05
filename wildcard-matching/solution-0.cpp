class Solution {
public:
  bool isMatch(string s, string p) {
    int dp[s.length()][p.length()];

    for (int i = 0; i < s.length(); ++i) {
      for (int j = 0; j < p.length(); ++j) {
        if (p[j] == '*') {
          
        } else if (p[j] == '?') {

        } else {

        }
      }
    }
  }
};