class Solution {
public:
  int calculateMaxSubArray(vector<int>& nums, int l, int r) {
    if (l == r) {
      return nums[l];
    }
    int m = (l + r) >> 1;
    int leftMax = calculateMaxSubArray(nums, l, m);
    int rightMax = calculateMaxSubArray(nums, m + 1, r);

    int sum = nums[m];
    int leftPartMax = sum;
    for (int i = m - 1; i >= l; --i) {
      sum += nums[i];
      leftPartMax = max(sum, leftPartMax);
    }
    sum = nums[m + 1];
    int rightPartMax = sum;
    for (int i = m + 2; i <= r; ++i) {
      sum += nums[i];
      rightPartMax = max(sum, rightPartMax);
    }
    return max(rightPartMax + leftPartMax, max(leftMax, rightMax));
  }
  int maxSubArray(vector<int>& nums) {
    return calculateMaxSubArray(nums, 0, nums.size() - 1);
  }
};