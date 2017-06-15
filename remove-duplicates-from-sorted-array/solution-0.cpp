class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        // Assumes there's a stack.
        int top = 1;
        int lastNumber = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != lastNumber) {
                nums[top++] = nums[i];
                lastNumber = nums[i];
            }
        }
        return top;
    }
};