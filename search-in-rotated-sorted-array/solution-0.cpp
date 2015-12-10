class Solution {
public:
	int find_min_index(const vector<int>& nums) {
		int l = 0;
		int r = nums.size() - 1;
		while (l < r) {
			if (nums[l] < nums[r]) {
				return l;
			}
			int m = l + ((r - l) >> 1);
			if (nums[m] >= nums[l]) {
				l = m + 1;
			} else {
				r = m;
			}
		}
		return r;
	}

	int range_binary_search(const vector<int>& nums, int left, int right, int target) {
		int l = left;
		int r = right;
		int ans = -1;
		while (l <= r) {
			int m = l + ((r - l) >> 1);
			if (nums[m] > target) {
				r = m - 1;
			} else if (nums[m] < target) {
				l = m + 1;
			} else {
				ans = m;
				break;
			}
		}
		return ans;
	}

    int search(vector<int>& nums, int target) {
    	int min_index = find_min_index(nums);
    	int ans = -1;
    	if (min_index == 0) {
    		ans = range_binary_search(nums, 0, nums.size() - 1, target);
    	} else {
    		if (nums[0] <= target && target <= nums[min_index - 1]) {
    			ans = range_binary_search(nums, 0, min_index - 1, target);
    		} else if (nums[min_index] <= target && target <= nums[nums.size() - 1]) {
    			ans = range_binary_search(nums, 0, min_index, nums.size() - 1);
    		} else {
    			ans = -1;
    		}
    	}
    	return ans;
    }
};