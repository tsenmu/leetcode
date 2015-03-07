class Solution {
public:
    string len(string& s, int m) {
      int l = m - 1; 
      int r = m + 1;
      char flag = char(255);
      string ans;
      if (s[m] != flag) {
        ans.push_back(s[m]);
      }
      string left;
      while(l >= 0 && r < s.length()) {
        if (s[l] != flag) {
          if (s[l] == s[r]) {
            left += s[l];
            ans += s[r];
          } else {
            break;
          }
        } 
        l--;
        r++;
      }
      reverse(left.begin(), left.end());
      ans = left + ans;
      return ans;
    }
    string longestPalindrome(string s) {
      string convertedString;
      for (int i = 0; i < s.length(); ++i) {
        convertedString.push_back(s[i]);
        if (i != s.length() - 1) {
          convertedString.push_back(char(255));
        }
      }
      string ans;
      for (int i = 0; i < convertedString.length(); ++i) {
        string candidate = len(convertedString, i);
        if (candidate.length() > ans.length()) {
          ans = candidate;
        }
      }
      return ans;
    }
};