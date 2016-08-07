class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        const int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
          for (int j = i - 1; j >= 0; --j)  {
            if (dp[j]) {
              if (wordDict.count(s.substr(j, i - j)) != 0) {
                dp[i] = true;
                break;
              }
            }
          }
        }

        return dp[n];
    }
};