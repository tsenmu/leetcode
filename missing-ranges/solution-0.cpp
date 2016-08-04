class Solution {
protected:
    string yieldRange(int begin, int end) {
        if (begin == end) {
            return to_string(begin);
        }
        return to_string(begin) + "->" + to_string(end);
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;       
        const int n = nums.size();
        if (n == 0) {
            result.push_back(yieldRange(lower, upper));
            return result;
        }

        // deal with the first one.
        if (nums[0] != lower) {
            result.push_back(yieldRange(lower, nums[0] - 1));
        }

        int begin = nums[0];
        int last = begin;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - last != 1) {
                result.push_back(yieldRange(last + 1, nums[i] - 1));
                begin = nums[i];
            }
            last = nums[i];
        }

        // deal with the last one.
        if (nums[n - 1] != upper) {
            result.push_back(yieldRange(nums[n - 1] + 1, upper));
        }

        return result;
    }
};