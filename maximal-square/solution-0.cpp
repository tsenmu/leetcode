class Solution {
public:
  int maximalSquare(vector<vector<char> >& matrix) {
    vector<vector<pair<int, int> > > dp;
    for (int i = 0; i < matrix.size(); ++i) {
      vector<char>& row = matrix[i];
      vector<pair<int, int> > dpRow;
      for (int j = 0; j < row.size(); ++j) {
        char ch = matrix[i][j];
        int r = 0;
        int c = 0;
        if (i == 0) {
          r = (ch == '1' ? 1 : 0);
        } else {

        }
        if (j == 0) {

        } else {
          
        }
        dpRow.push_back(make_pair(r, c));
      }
    }
  }
};