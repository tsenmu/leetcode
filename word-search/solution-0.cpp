class Solution {
public:

  bool dfs(vector<vector<char>>& board,
    vector<vector<bool>>& visited, string& word, int index, int lastX, int lastY) {
    if (index == word.size()) {
      return true;
    }

    char& ch = word[index];

    bool ret = false;

    if (index == 0) {
      for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
          if (ch == board[i][j]) {
            visited[i][j] = true;;
            ret |= dfs(board, visited, word, index + 1, i, j);
            visited[i][j] = false;

            if (ret) {
              return true;
            }
          } 
        }
      } 
    } else {
      for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
          if (i != 0 && j != 0) {
            continue;
          }
          int x = i + lastX;
          int y = j + lastY;
          if (isValidCoordinate(board, visited, x, y) && board[x][y] == ch) {
            visited[x][y] = true;
            ret |= dfs(board, visited, word, index + 1, x, y);
            visited[x][y] = false;

            if (ret) {
              return true;
            }
          }
        } 
      } 
    }
    return false;
  }

  bool isValidCoordinate(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y) {
    return x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !visited[x][y];
  }

  bool exist(vector<vector<char>>& board, string word) {
    if (board.size() == 0) {
      return word.length() == 0; 
    }
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    return dfs(board, visited, word, 0, -1, -1);
  }
};