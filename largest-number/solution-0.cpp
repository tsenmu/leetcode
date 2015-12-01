class Solution {
public:
  string largestNumber(vector<int>& nums) {
    vector<string> strs;
    for (int i = 0; i < nums.size(); ++i) {
      ostringstream oss;
      oss << nums[i];
      strs.push_back(oss.str());
    }
    sort(strs.begin(), strs.end());

    string ans;
    for (int i = 0; i < strs.size(); ++i) {
      ans += strs[i];
    }
    return ans;
  }
};