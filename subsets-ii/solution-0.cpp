class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      
      set<vector<int>> S;
      for (int i = 0; i < (1 << nums.size()); ++i) {
        vector<int> result;
        for (int j = 0; j < nums.size(); ++j) {
          if ((1 << j) & i) {
            result.push_back(nums[j]);
          }
        }
        S.insert(result);
      }
      vector<vector<int>> results;
      for ( set<vector<int>>::iterator it = S.begin(); it != S.end(); ++it) {
         results.push_back(*it);
      }
      return results;
    }
};