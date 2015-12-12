class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);

        long long product = 1;       
        int zero_count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                product *= (long long) (nums[i]);
            } else {
                zero_count++;
            }
        }

        if (zero_count <= 1) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == 0) {
                    ans[i] = (int) product;
                } else {
                    if (zero_count == 1) {
                        ans[i] = 0;
                    } else {
                        ans[i] = product / nums[i];
                    }
                }
            }
        }

        return ans;
    }
};