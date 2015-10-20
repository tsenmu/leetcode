class Solution {
public:
  int titleToNumber(string s) {
    int ans = 0;
    int pow = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
      int digit = (int)(s[i] - 'A') + 1;
      ans += digit * pow;
      pow *= 26;
    }
    return ans;
  }
};