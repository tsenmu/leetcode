class Solution {
public:
  int strStr(string haystack, string needle) {
    for (int i = 0; i < (int)haystack.length() - (int)needle.length() + 1; ++i) {
      bool found = true;
      for (int j = 0; j < needle.length(); ++j) {
        if (haystack[i + j] != needle[j]) {
          found = false;
          break;
        }
      }
      if (found) {
        return i;
      }
    }      
    return -1;
  }
};