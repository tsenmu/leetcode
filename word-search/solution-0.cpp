class Solution {
public:

  bool dfs(vector<vector<char>>& board,
    vector<vector<bool>>& visited, string& word) {
    
  }

  bool exist(vector<vector<char>>& board, string word) {
    if (board.size() == 0) {
      return word.length() == 0; 
    }
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    return dfs(board, visited, word);
  }
};