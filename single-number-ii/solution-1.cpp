class Solution {
public:
  int singleNumber(int A[], int n) {
    int vis[32] = {0};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 32; ++j) {
        if (A[i] & (1 << j)) {
          vis[j]++;
          if (vis[j] == 3) {
            vis[j] = 0;
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
      ans |= (vis[i] ? (1 << i) : 0);
    }
    return ans;
  }
};
