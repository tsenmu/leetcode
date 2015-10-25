class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }     
    map<char, char> M1, M2;
    for (int i = 0; i < s.length(); ++i) {
      if (M1.count(s[i]) == 0) {
        M1[s[i]] = t[i];
      } else {
        if (M1[s[i]] != t[i]) {
          return false;
        }
      }

      if (M2.count(t[i]) == 0) {
        M2[t[i]] = s[i];
      } else {
        if (M2[t[i]] != s[i]) {
          return false;
        }
      }
    }
    return true;
  }
};