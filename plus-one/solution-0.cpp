class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
      vector<int> ans(digits);
      int increment = 1;
      for (int i = ans.size() - 1; i >= 0; --i) {
          ans[i] += increment;
          increment = ans[i] / 10;
          ans[i] %= 10;
      }       
      if (increment) {
        ans.insert(ans.begin(), increment);
      }
      return ans;
    }
};