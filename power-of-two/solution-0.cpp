class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n & (1 << 31)) {
        return false;
    }
    int num = 0;
    for (int i = 0; i < 31; ++i) {
      if (n & (1 << i)) {
        num++;
      }
    }
    return num == 1;
  }
};