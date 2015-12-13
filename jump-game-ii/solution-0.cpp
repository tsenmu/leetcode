class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int reach = 0;      

        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0; 

        for (int i = 0; i < nums.size(); ++i) {
            if (i + nums[i] > reach) {
                reach = i + nums[i];
                for (int j = i + 1; j <= reach && j < nums.size(); ++j) {
                    dp[j] = min(dp[i] + 1, dp[j]);
                }
            }
        }

        return dp[nums.size() - 1];
    }
};