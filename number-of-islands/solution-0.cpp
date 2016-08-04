class Solution {
protected:
    bool labelIsland(int r, int c, 
        vector<vector<int>>& labels, int nextNewLabel) {

        const int row = labels.size();
        const int col = labels[0].size();

        if (!isValidCoordinate(r, c, row, col)) {
            return false;
        }
        
        if (labels[r][c] == 0 || labels[r][c] > 1) {
            return false;
        }
        
        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};
        
        bool visited = false;

        if (labels[r][c] == 1) {
            labels[r][c] = nextNewLabel;

            for (int i = 0; i < 4; ++i) {
                labelIsland(r + dr[i], c + dc[i], labels, nextNewLabel);
            }

            visited = true;
        } else {
            labels[r][c] = -1;
        }
        

        return visited;
    }

    bool isValidCoordinate(int r, int c, int row, int col) {
        return r >= 0 && c >= 0 && r < row && c < col; 
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }

        const int row = grid.size();
        const int col = grid[0].size();

        vector<vector<int>> labels(row, vector<int>(col, 0));

        // initialize the label with grid info.
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    labels[i][j] = 1;
                }
            }
        }
        
        

        int nextNewLabel = 2;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (labelIsland(i, j, labels, nextNewLabel)) {
                    nextNewLabel++; 
                }
            }
        }

        return nextNewLabel - 2;
    }
};