class Solution {
public:
  int hIndex(vector<int>& citations) {
    const int n = citations.size();
    if (n == 0) {
      return 0;
    }

    int l = 0;      
    int r = n - 1;
    int m = 0;
    while (l <= r) {
      m = (l + r) >> 1; 
      if (citations[n - 1 - m] >= m + 1) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return l;
  }
};