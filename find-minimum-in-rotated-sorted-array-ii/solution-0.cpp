class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;              
        int r = nums.size() - 1;

        while (l < r) {

            int m = l + ((r - l) >> 1);

            if (nums[m] > nums[r]) {
                l = m + 1;
            } else if (nums[m] < nums[r]) {
                r = m;
            } else {
                if (nums[r - 1] <= nums[r]) {
                    r--;
                } else {
                    break;
                }
            }
        }

        return nums[r];
    }
};