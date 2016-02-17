class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int ans = 0;
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                if (nums[i] + nums[j] + nums[k] >= target) {
                    k--;
                } else {
                    j++;
                    ans += k - j + 1;
                }
            }
        }
        return ans;
    }
};