class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
          return false;
        }

        return countOneInIntegerRepresentation(n) == 1;
    }

    int countOneInIntegerRepresentation(int n) {
      int ans = 0;
      for (int i = 0; i < 32; ++i)  {
        if (n & (1 << i)) {
          ++ans;
        }
      }
      return ans;
    }
};