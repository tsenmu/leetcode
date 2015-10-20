class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i = 0; i < m; ++i) {
      nums1[nums1.size() - i - 1] = nums1[m - i - 1];
    }
    int i = 0;
    int j = 0;
    int top = 0;
    while (i < m && j < n) {
      if (nums1[nums1.size() - m + i] < nums2[j]) {
          nums1[top++] = nums1[nums1.size() - m + i++];
      } else {
        nums1[top++] = nums2[j++];
      }
    }
    while (i < m) {
      nums1[top++] = nums1[nums1.size() - m + i++];
    }
    while(j < n) {
      nums1[top++] = nums2[j++];
    }
  }
};