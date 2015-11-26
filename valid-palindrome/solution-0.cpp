class Solution {
public:
  bool isAlphanumeric(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
  }



  bool isPalindrome(string s) {
    for (int i = 0; i < s.length(); ++i) {
      s[i] = tolower(s[i]);
    }
    int l = 0;
    int r = s.length() - 1;
    while(l < r) {
      if (!isAlphanumeric(s[l])) {
        l++;
      } else if (!isAlphanumeric(s[r])) {
        r--;
      } else {
        if (s[l] != s[r]) {
          return false;
        } 
        l++;
        r--;
      }
    }
    return true;
  }
};