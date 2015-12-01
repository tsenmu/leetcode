class Solution {
public:
  int maximumGap(vector<int>& nums) {
    vector<int> buckets(2, 0);
    vector<int> holder(nums.size(), 0);
    for (int i = 0; i < 31; ++i) {
      buckets.assign(buckets.size(), 0);
      for (int j = 0; j < nums.size(); ++j) {
        if (nums[j] & (1 << i)) {
          buckets[1]++;
        } else {
          buckets[0]++;
        }
      } 
      buckets[1] += buckets[0];
      for (int j = nums.size() - 1; j >= 0; --j) {
        if (nums[j] & (1 << i)) {
          holder[--buckets[1]] = nums[j];
        } else {
          holder[--buckets[0]] = nums[j];
        }
      } 
      nums = holder;
    }

    int ans = 0;
    for (int i = 1; i < nums.size(); ++i) {
      ans = max(ans, nums[i] - nums[i - 1]);
    }
    return ans;
  }
};