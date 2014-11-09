class Solution {
public:
  int romanToInt(string s) {
    char b = ' ';
    int ret = 0;
    for (int i = 0; i < s.length(); ++i) {
      char ch = s[i];
      switch (ch) {
        case 'I':
          ret += 1;
          break;
        case 'V':
          ret += b == 'I' ? 3 : 5;
          break;
        case 'X':
          ret += b == 'I' ? 8 : 10;
          break;
        case 'L':
          ret += b == 'X' ? 30 : 50;
          break;
        case 'C':
          ret += b == 'X' ? 80 : 100;
          break;
        case 'D':
          ret += b == 'C' ? 300 : 500;
          break;
        case 'M':
          ret += b == 'C' ? 800 : 1000;
          break;
      }
      b = ch;
    }
    return ret;
  }
};
