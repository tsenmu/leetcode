class Solution {

protected:
    string yieldRange(int begin, int end) {
      if (begin == end) {
        return to_string(begin);
      } 
      return to_string(begin) + "->" + to_string(end);
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
      const int n = nums.size();

      vector<string> result;
      
      if (n == 0) {
          return result;
      }

      if (n == 1) {
        result.push_back(yieldRange(nums[0], nums[0]));
        return result;
      }

      int last = nums[0];
      int begin = last;
      for (int i = 1; i < n; ++i) {
        if (nums[i] - last != 1) {
          result.push_back(yieldRange(begin, last));
          begin = nums[i];
        }
        last = nums[i];
      }

      result.push_back(yieldRange(begin, nums[n - 1]));

      return result;
    }
};