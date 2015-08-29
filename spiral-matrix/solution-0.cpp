class Solution {
public:
    bool isTurning(vector<vector<int>>& matrix, vector<vector<bool>>& visited, 
        char direction, int& x, int& y,
        int row, int col) {
      int originalX = x;
      int originalY = y;
      switch (direction) {
      case 'r':
        x++;
        if (col == x) {
          x--;
          return true;
        }
        break;
      case 'd':
        y++;
        if (row == y) {
          y--;
          return true;
        }
        break;
      case 'l':
        x--;
        if (col == 0) {
          x++;
          return true;
        }
        break;
      case 'u':
        y--;
        if (row == 0) {
          y++;
          return true;
        }
        break;
      }
      if (visited[x][y]) {
        x = originalX;
        y = originalY;
        return true;
      }
      return false;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> result;
      if (matrix.size() == 0) {
        return result;
      }
      if (matrix[0].size() == 0) {
        return result;
      }

      int row = matrix.size();
      int col = matrix[0].size();

      vector<vector<bool>> visited;

      vector<bool> visitedRow;
      for (int j = 0; j < col; ++j) {
        visitedRow.push_back(false);
      }
      for (int i = 0; i < row; ++i) {
        visited.push_back(visitedRow);
      }

      int visitedNum = 0;

      vector<char> directions;
      directions.push_back('r');
      directions.push_back('d');
      directions.push_back('l');
      directions.push_back('u');
      int next_direction = 0;
      int x = 0;
      int y = 0;
      while (visitedNum < row * col) {
        if (!visited[x][y]) {
          result.push_back(matrix[x][y]);
          visited[x][y] = true;
          visitedNum++;
        }
        if (isTurning(matrix, visited, directions[next_direction], x, y, row, col)) {
          next_direction = (next_direction + 1) % 4;
        }
      }
      return result;
    }
};