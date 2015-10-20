class Solution {
public:
  bool validateSize(vector<vector<char>>& board) {
    if (board.size() != 9) {
      return false;
    }
    for (int i = 0; i < 9; ++i) {
      if (board[i].size() != 9) {
        return false;
      }
    }
    return true;
  }

  bool validateRows(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
      int counts[10];
      memset(counts, 0, sizeof counts);
      for (int j = 0; j < 9; ++j) {
        char ch = board[j][i];
        if (ch != '.') {
          counts[ch - '0']++;
          if (counts[ch - '0'] > 1) {
            return false;
          }
        } 
      }
    }
    return true;
  }

  bool validateCols(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
      int counts[10];
      memset(counts, 0, sizeof counts);
      for (int j = 0; j < 9; ++j) {
        char ch = board[i][j];
        if (ch != '.') {
          counts[ch - '0']++;
          if (counts[ch - '0'] > 1) {
            return false;
          }
        } 
      }
    }
    return true;
  }

  bool validateGrids(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        int counts[10];
        memset(counts, 0, sizeof counts);
        for (int ii = 0; ii < 3; ++ii) {
          for (int jj = 0; jj < 3; ++jj) {
            char ch = board[i * 3 + ii][j * 3 + jj];
            if (ch != '.') {
              counts[ch - '0']++;
              if (counts[ch - '0'] > 1) {
                return false;
              }
            } 
          }
        }
      }
    }
    return true;
  }

  bool isValidSudoku(vector<vector<char>>& board) {
    return validateSize(board) && validateRows(board) && validateCols(board) && validateGrids(board);
  }

};







