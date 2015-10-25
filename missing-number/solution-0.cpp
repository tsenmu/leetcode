class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int sum = ((0 + nums.size()) * (nums.size() + 1)) >> 1;
    for (int i = 0; i < nums.size(); ++i) {
      sum -= nums[i];
    }
    return sum;
  }
};