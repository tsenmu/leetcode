class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans; 

        int n = nums.size();

        int sum = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int l = j + 1;
                int r = n - 1;
                while (l < r) {
                    if (l > j + 1 && nums[l - 1] == nums[l]) {
                        l++;
                        continue;
                    }

                    if (r < n - 1 && nums[r + 1] == nums[r]) {
                        r--;
                        continue;
                    }

                    sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum < target) {
                        l++; 
                    } else if (sum > target) {
                        r--;
                    } else {
                        vector<int> solution = {nums[i], nums[j], nums[l], nums[r]};
                        ans.push_back(solution);
                        l++;
                        r--;
                    }
                }
            }
        }

        return ans;
    }
};