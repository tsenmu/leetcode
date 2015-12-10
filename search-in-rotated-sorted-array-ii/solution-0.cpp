class Solution {
public:

    int find_min_index(const vector<int>& nums) {
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
       return r;
    }

    int range_binary_search(const vector<int>& nums, int left, int right, int target) {
        int l = left;
        int r = right;

        int ans = -1;
        while (l <= r) {
            int m = l + ((r - l) >> 1) ;
            if (nums[m] > target) {
                r = m - 1; 
            } else if (nums[m] < target) {
                l =  m + 1; 
            } else {
                ans = m;
                break;
            }
        }

        return ans;
    }

    bool search(vector<int>& nums, int target) {
        int min_index = find_min_index(nums);
        printf("%d\n", min_index);
        int target_index = -1;
        if (min_index == 0) {
            target_index = range_binary_search(nums, 0, nums.size() - 1, target);
        } else {
            if (nums[0] <= target && target <= nums[min_index - 1]) {
               target_index = range_binary_search(nums, 0, min_index - 1, target);
            } else if (nums[min_index] <= target && target <= nums[nums.size() - 1]) {
               target_index = range_binary_search(nums, min_index, nums.size() - 1, target);
            } 
        }

        return target_index != -1; 

    }
};