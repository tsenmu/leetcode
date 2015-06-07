class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      map<int, vector<int> > M;
      for (int i = 0; i < nums.size(); ++i) {
        M[nums[i]].push_back(i);
      }
      for (map<int, vector<int> >::iterator it = M.begin(); it != M.end(); ++it) {
        vector<int> v = it->second;
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); ++i) {
          if (v[i] - v[i - 1] <= k) {
            return true;
          }
        }
      }
      return false;
    }
};