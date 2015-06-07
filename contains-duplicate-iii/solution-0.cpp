class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      vector<pair<long long, int> > numsWithIndex;
      for (int i = 0; i < nums.size(); ++i) {
        numsWithIndex.push_back(make_pair(nums[i], i));
      } 
      sort(numsWithIndex.begin(), numsWithIndex.end());
      for (int i = 0; i < numsWithIndex.size(); ++i) {
        for (int j = i + 1; j < numsWithIndex.size(); ++j) {
          if (numsWithIndex[j].first  - numsWithIndex[i].first <= t) {
            if(abs(numsWithIndex[j].second - numsWithIndex[i].second) <= k) {
              return true;
            }
          } else {
            break;
          }
        }
      }      
      return false;
    }
};