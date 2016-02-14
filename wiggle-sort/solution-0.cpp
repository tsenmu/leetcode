class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (i & 1) {
                if (nums[i - 1] > nums[i]) {
                    swap(nums[i - 1], nums[i]);
                }
            } else {
                if (nums[i - 1] < nums[i]) {
                    swap(nums[i - 1], nums[i]);
                }
            }
        }
    }
};