class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        const int size = nums.size();
        const vector<pair<int, int> >& range_k = minSubArrayRanges(nums, k);
        const vector<pair<int, int> >& range_zero = minSubArrayRanges(nums, 0);
        
        unordered_map<int, int> ends;
        unordered_map<int, int> begins;
        for (auto& range : range_zero) {
            
        }

        for (auto& range : range_k) {

        }
    }
    vector<pair<int, int> > minSubArrayRanges(const vector<int>& nums, int k) {
        vector<pair<int, int> > ranges;
        if (nums.size() == 0) {
            return ranges;
        }
        int left = 0;
        int running_sum = 0;
        for (int right = 0; right < nums.size(); ++right) {
            running_sum += nums[right];
            while (running_sum > k && left <= right) {
                running_sum -= nums[left];
                left++;
            }
            if (running_sum == k && left <= right) {
                ranges.push_back(make_pair(left, right));
            }
        }
        return ranges;
    }
};