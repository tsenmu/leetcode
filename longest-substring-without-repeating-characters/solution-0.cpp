class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int M[256];
      memset(M, -1, sizeof M);
      int ans = 0;
      int candidate = 0;
      int start = 0;
      for (int i = 0; i < s.length(); ++i) {
        char ch = s[i];
        int& lastIndex = M[(int)ch];
        if (lastIndex == -1) {
          candidate++;
        } else {
          if (start > lastIndex) {
            candidate++;
          } else {
            candidate = i - lastIndex;
            start = lastIndex + 1;
          }
        }
        lastIndex = i;
        ans = max(ans, candidate);
      }
      return ans;
    }
};