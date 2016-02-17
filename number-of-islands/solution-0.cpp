class Solution {
protected:
    bool is_valid(int br, int bc, int r, int c) {
        return br >= 0 && bc >= 0 && br < r && bc < c;
    }
    void expand(int br, int bc, vector<vector<int>>& colours) {
        int row = colours.size();
        int col = colours[0].size();
        if (!is_valid(br, bc, row, col)) {
            return;
        }

        if (colours[br][bc] != 1) {
            return;
        }
        
        colours[br][bc] = 2;

        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; ++i) {
            int nr = br + dr[i];
            int nc = bc + dc[i];
            expand(nr, nc, colours);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0; 
        }
        const int row = grid.size();
        const int col = grid[0].size();
        vector<vector<int>> colours(row, vector<int>(col, 0));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    colours[i][j] = 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (colours[i][j] == 1) {
                    expand(i, j, colours);
                    ans++;
                }
            }
        }
        return ans;
    }
}; 