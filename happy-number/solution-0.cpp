class Solution {
public:
  int dss(int n) {
    int ans = 0;
    while (n) {
      int digit = n % 10;
      ans += digit * digit;
      n /= 10;
    }
    return ans;
  }
  bool isHappy(int n) {
    unordered_set<int> s;  
    while (n != 1) {
      if (s.count(n) == 1) {
        return false;
      } else {
        s.insert(n);
        n = dss(n);
      }
    }
    return true;
  }
};