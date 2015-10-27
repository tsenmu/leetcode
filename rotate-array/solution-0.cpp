class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    vector<int> partial(nums.begin() + (nums.size() - k), nums.end());      
    nums.erase(nums.begin() + (nums.size() - k), nums.end());
    nums.insert(nums.begin(), partial.begin(), partial.end()); 
  }
};