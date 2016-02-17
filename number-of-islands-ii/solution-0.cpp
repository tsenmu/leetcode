class Solution {
protected:
    vector<int> m_diset;
    // will return target's parent
    int diset_find(int target) {
        if (m_diset[target] == target) {
            return target;
        }
        return m_diset[target] = diset_find(m_diset[target]);
    }

    // will union two sets.
    bool diset_union(int x, int y) {
        int xp = diset_find(x);
        int yp = diset_find(y);
        if (xp == yp) {
            return false;
        } 
        m_diset[xp] = yp;
        return true;
    }

    // return the new set numbering
    int diset_add() {
        m_diset.push_back(m_diset.size());
        return m_diset.size() - 1;
    }

    bool is_valid(int r, int c, int m, int n) {
        return r >= 0 && r < m && c >= 0 && c < n; 
    }
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        m_diset.clear();
        m_diset.push_back(0);
        vector<vector<int>> matrix(m, vector<int>(n, 0));

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        vector<int> ans;
        int islands = 0;

        for (int i = 0; i < positions.size(); ++i) {
            int r = positions[i].first;
            int c = positions[i].second;

            vector<int> neighbour_colours;
            // directions
            for (int j = 0; j < 4; ++j) {
                int nr = r + dx[j];
                int nc = c + dy[j];
                if (is_valid(nr, nc, m, n) && matrix[nr][nc] != 0) {
                    neighbour_colours.push_back(matrix[nr][nc]);
                }
            }

            if (neighbour_colours.size() == 0) {
                matrix[r][c] = diset_add();
                islands++;
            } else if (neighbour_colours.size() == 1) {
                matrix[r][c] = neighbour_colours[0];
            } else {
                for (int ii = 0; ii < neighbour_colours.size(); ++ii) {
                    for (int jj = ii + 1; jj < neighbour_colours.size(); ++jj) {
                        if (diset_union(neighbour_colours[ii], neighbour_colours[jj])) {
                            islands--;
                        } 
                    }
                }
                matrix[r][c] = neighbour_colours[0];
            }

            ans.push_back(islands);
        }

        return ans;
    }
};



















