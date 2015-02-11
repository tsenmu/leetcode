class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
      vector<int> firstColumnElements;
      for (int i = 0; i < matrix.size(); ++i) {
        firstColumnElements.push_back(matrix[i][0]);
      }
      auto upper = upper_bound(firstColumnElements.begin(), firstColumnElements.end(), target);
      if (upper == firstColumnElements.begin()) {
        return false;
      }
      upper--;
      int row = upper - firstColumnElements.begin();
      auto lower = lower_bound(matrix[row].begin(), matrix[row].end(), target);
      if (*lower == target) {
        return true;
      }
      return false;
    }
};