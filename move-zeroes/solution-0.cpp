class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int numZero = 0;
    int top = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        numZero++;
      } else {
        nums[top++] = nums[i];
      }
    }
    for (int i = nums.size() - numZero; i < nums.size(); ++i) {
      nums[i] = 0;
    }
  }
};