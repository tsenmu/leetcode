// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    long long l = 1;      
    long long r = n;
    long long m;
    while (l <= r) {
      m = (l + r) >> 1; 
      if (isBadVersion(m)) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    if (!isBadVersion(l)) {
      l--;
    }
    return l;
  }
};