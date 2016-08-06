class Solution {
protected:
    int diset_find(int x, vector<int>& diset) {
        if (diset[x] == x) {
            return x; 
        }
        return diset[x] = diset_find(diset[x], diset);
    }

    bool diset_union(int x, int y, vector<int>& diset) {
        int xr = diset_find(x, diset);
        int yr = diset_find(y, diset);

        if (xr == yr) {
            return false;
        }
        diset[xr] = yr;
        return true;
    }

    int diset_insert(vector<int>& diset) {
        int ne = diset.size();
        diset.push_back(ne);
        return ne;
    }


    bool isValidCoordinate(int r, int c, int row, int col) {
        return r >= 0 && c >= 0 && r < row && c < col; 
    }
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {

        vector<int> diset;
        diset_insert(diset);

        static int dr[4] = {-1, 1, 0, 0};
        static int dc[4] = {0, 0, -1, 1};
        vector<vector<int>> grid(m, vector<int>(n, 0));
        int ans = 0;
        vector<int> ret;
        for (int i = 0; i < positions.size(); ++i) {
            int r = positions[i].first; 
            int c = positions[i].second;

            set<int> islands;
            for (int j = 0; j < 4; ++j) {
                int nr = r + dr[j];
                int nc = c + dc[j];
                if (isValidCoordinate(nr, nc, m, n))  {
                    if (grid[nr][nc]) {
                        islands.insert(grid[nr][nc]);
                    }
                }
            }

            vector<int> islandsVec(islands.begin(), islands.end());
            if (islandsVec.size() == 0) {
                grid[r][c] = diset_insert(diset);
                ans++;
            } else if (islandsVec.size() == 1) {
                grid[r][c] = islandsVec[0];
            } else {
                int last = islandsVec[0];
                grid[r][c] = last;
                for (int j = 1; j < islandsVec.size(); ++j) {
                    if (diset_union(islandsVec[j], islandsVec[j - 1], diset)) {
                        ans--;
                    }
                }
            }
            ret.push_back(ans);
        }
        return ret;
    }
};



