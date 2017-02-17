class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      const int size = nums.size();
      int next_position = 0; 
      for (int i = 0; i < size; ++i) {
        if (nums[i] != 0) {
          nums[next_position] = nums[i];
          next_position++;
        }
      }
    }
};