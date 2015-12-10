class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        
        int l = 0;
        int r = nums.size() - 1;

        int ll = -1;
        int rr = -1;
        int mm = -1;

        while (l <= r) {
            int m = l + ((r - l) >> 1);

            if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                ll = l;
                rr = r;
                mm = m;
                break;
            }
        }
        
        if (mm == -1) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        // search left
        l = ll;
        r = mm;
        while (l < r) {
            int m = l + ((r - l) >> 1);

            if (nums[m] != target) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        result.push_back(r);

        // search right
        l = mm;
        r = rr;
        while (l <= r) {
            int m = l + ((r - l) >> 1);

            if (nums[m] != target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        result.push_back(r);
        

        return result;

    }
};