// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int l = 1;
    int r = n;      
    int m;
    int result;
    while (l <= r) {
      m = l + ((r - l) >> 1);
      result = isBadVersion(m);
      if (result) {
        if (m > 0 && !isBadVersion(m - 1) || m == 0) {
          return m;
        } else {
          r = m - 1;
        }
      } else {
        l = m + 1;
      }
    }
    return m;
  }
};