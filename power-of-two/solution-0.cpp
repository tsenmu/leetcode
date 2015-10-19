class Solution {
public:
  bool isPowerOfTwo(int n) {
    int num = 0;
    for (int i = 0; i < 32; ++i) {
      if (n & (1 << i)) {
        num++;
      }
    }
    return num == 1;
  }
};