class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
      return results;
    }
};