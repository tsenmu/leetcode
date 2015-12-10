class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int l = 0;       
        int r = nums.size() - 1;
        while (l < r) {
            
            int m = l + ((r - l) >> 1);
            
            if (l == m) {
                return min(nums[l], nums[r]);
            }

            if (nums[l] < nums[m] && nums[m] < nums[r]) {
                r = l;
            } else if (nums[l] < nums[m] && nums[m] > nums[r]) {
                l = m + 1;
            } else if (nums[l] > nums[m] && nums[m] < nums[r]) {
                r = m;
            } 
        }
        
        return nums[r];
    }
};