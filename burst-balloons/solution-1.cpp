class Solution {
public:
    int dfs(vector<int>& nums, vector<vector<int>>& mem, int left, int right) {
        if (right - left < 2) {
            return 0;
        }

        if (mem[left][right] != -1) {
            return mem[left][right];
        }

        int ans = 0;
        for (int i = left + 1; i < right; ++i) {
            ans = max(ans, nums[i] * nums[left] * nums[right] +
                dfs(nums, mem, left, i) + dfs(nums, mem, i, right));
        }

        return mem[left][right] = ans;
    }

    int maxCoins(vector<int>& input) {
        vector<int> nums(input.size() + 2, 0);
        nums[0] = nums[input.size() + 1] = 1;
        for (int i = 0; i < input.size(); ++i) {
            nums[i + 1] = input[i];
        }
        int n = nums.size();
        vector<vector<int>> mem(n, vector<int>(n, -1));

        return dfs(nums, mem, 0, n - 1);
    } 
};