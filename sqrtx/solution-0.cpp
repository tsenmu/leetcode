class Solution {
public:
  int mySqrt(int x) {
    if (x == 0) {
      return 0;
    }

    int l = 1;
    int r = x >> 1;
    int m = l;
    while (l <= r) {
      m = l + ((r - l) >> 1);
      int sqm = m * m;
      if (sqm == x) {
        break;
      } else if (sqm > x) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    if (m * m > x) {
        m--;
    }
    return m;
  }
};