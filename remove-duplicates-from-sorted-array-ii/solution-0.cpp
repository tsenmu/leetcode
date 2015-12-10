class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int top = 1;
        int counter = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                counter = 1;
                nums[top++] = nums[i];
            } else {
                counter++;
                if (counter == 2) {
                    nums[top++] = nums[i];
                } 
            }
        }
        return top;
    }
};