class Solution {
public:
    int searchInsert(int A[], int n, int target) {
      int l = 0;
      int r = n - 1;
      int m;
      while (l <= r) {
        m = (l + r) >> 1;
        if (target < A[m]) {
          r = m - 1;
        } else if (target > A[m]) {
          l = m + 1;
        } else {
          return m;
        }
      }
      return A[m] > target ? m : m + 1; 
    }
};
