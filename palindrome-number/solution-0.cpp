class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0) return false;
      int x_copied = x;
      int v = 0;
      while (x) {
        v *= 10;
        v += x % 10;
        x /= 10;
      }
      return v == x_copied;
    }
};
