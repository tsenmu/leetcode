class Solution {
public:
    vector<vector<int>> results;

    void findSubsetsOfSize(vector<int>& nums, vector<int>& result, int startPos, int numFound, int n) {
      if (numFound == n) {
        results.push_back(result);
        return;
      }
      for (int i = startPos; i < nums.size(); i++) {
        result.push_back(nums[i]);
        findSubsetsOfSize(nums, result, i + 1, numFound + 1, n);
        result.pop_back();
      }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      results.clear();
      for (int i = 1; i <= nums.size(); ++i) {
        vector<int> result;
        findSubsetsOfSize(nums, result, 0, 0, i);
      }
      results.push_back(vector<int>());
      return results;
    }
};