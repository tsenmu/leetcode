class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        const int n = nums.size();

        if (n == 0) {
            return 0;
        }

        vector<int> sum(n, 0);
        sum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i - 1] + nums[i];
        }

        return sum[upper] - sum[lower] + nums[lower];
    }
};