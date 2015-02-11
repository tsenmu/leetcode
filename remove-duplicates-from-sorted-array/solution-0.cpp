class Solution {
public:
    int removeDuplicates(int A[], int n) {
      if (n == 0) {
        return 0;
      }
      int t = 1; 
      int c = A[0];
      for (int i = 1; i < n; ++i) {
        if (c != A[i]) {
          c = A[i];
          A[t++] = c;
        }
      }
      return t;
    }
};