class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> ans;
    for (int i = 0; i < rowIndex + 1; ++i) {
      ans.push_back(0);
    }
    ans[0] = 1;
    for (int i = 1; i < rowIndex + 1; ++i) {
      for (int j = i; j >= 0; --j) {
        ans[j] = ans[j - 1] + ans[j];
      }
    }
    return ans;
  }
};