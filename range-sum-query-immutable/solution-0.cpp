class NumArray {
public:
  vector<int> sums;
  NumArray(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
      sums.push_back(i ? nums[i] + sums[i - 1] : nums[i]);
    }
  }

  int sumRange(int i, int j) {
    if (i > j) return sumRange(j, i);
    if (i < 0) return sumRange(0, j);
    if (j >= sums.size()) return sumRange(i, sums.size() - 1);
    return sums[j] - (i ? sums[i - 1] : 0);
  }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);