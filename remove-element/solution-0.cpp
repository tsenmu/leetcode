class Solution {
public:
    int removeElement(int A[], int n, int elem) {
      int r = n - 1;
      int l = 0;
      while (l <= r) {
        if (A[r] == elem) {
          r--;
        } else if (A[l] == elem) {
          swap(A[l], A[r]);
          l++;
        } else {
          l++;
        }
      }
      return r + 1;
    }
};
