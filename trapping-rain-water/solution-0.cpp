class Solution {
public:
  int trap(int A[], int n) {
    int l = 0;
    int r = n - 1;
    int lm = 0;
    int rm = 0;
    int v = 0;
    while (l <= r) {
      int lh = A[l];
      int rh = A[r];
      if (lh < rh) {
        if (lh > lm) {
          lm = lh;
        }
        v += lm - A[l];
        ++l;
      } else {
        if (rh > rm) {
          rm = rh;
        }
        v += rm - A[r];
        --r;
      }
    }
    return v;
  }
};
