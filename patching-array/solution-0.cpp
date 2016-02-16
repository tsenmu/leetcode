class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long max_reach = 0;
        int index = 0;
        int ans = 0;
        while (max_reach < n) {
            if (index < nums.size() && nums[index] <= max_reach + 1) {
                max_reach += nums[index];
                index++;
            } else {
                max_reach += max_reach + 1;
                ans++;
            }
        }
        return ans;
    }
};