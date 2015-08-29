class Solution {
public:
    bool cmp(const vector<int>& a, const vector<int>& b) {
      if (a.size() != b.size()) {
        return false;
      }
      for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
          return false;
        }
      }
      return true;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> results;
      for (int i = 0; i < (1 << nums.size()); ++i) {
        vector<int> result;
        for (int j = 0; j < nums.size(); ++j) {
          if ((1 << j) & i) {
            result.push_back(nums[j]);
          }
        }
        results.push_back(result);
      }
      std::vector<vector<int>>::iterator it = unique(results.begin(), results.end(), cmp);
      results.resize( std::distance(results.begin(),it));
      return results;
    }
};