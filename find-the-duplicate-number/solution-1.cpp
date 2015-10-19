class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < 32; ++i) {
      int mask = (1 << i);
      int count = 0;
      for (int j = 0; j < nums.size(); ++j) {
        count += bool(nums[j] & mask) - bool(j & mask);
      }
      if (count > 0) {
        result |= mask;
      }
    }
    return result;
  }
};