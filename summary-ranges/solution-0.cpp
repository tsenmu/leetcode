class Solution {
public:
    std::string getRange(int start, int len) {
      std::ostringstream oss;
      if (len > 1) {
        oss << start << "->" << start + len - 1;
      } else {
        oss << start;
      }
      return oss.str();
    }
    vector<string> summaryRanges(vector<int>& nums) {
      vector<string> result;
      if (nums.size() == 0) { 
        return result;
      }
      int start = nums[0];
      for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] + 0L - nums[i - 1] > 1) {
          result.push_back(getRange(start, nums[i - 1] - start + 1));
          start = nums[i];
        }
      }
      result.push_back(getRange(start, nums[nums.size() - 1] - start + 1));
      return result;
    }
};