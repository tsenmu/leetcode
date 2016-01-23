class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        const int n = nums.size();

        if (n == 0) return 0;

        unordered_map<int, int> M;

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            if (M.count(val) == 0) {
                int left = M.count(val - 1) ? M[val - 1] : 0;
                int right = M.count(val + 1) ? M[val + 1] : 0;
                int total = 1 + left + right;
                M[val] = total;
                ans = max(ans, total);
                
                M[val - left] = total;
                M[val + right] = total;
            }
        }

        return ans;
    }
};