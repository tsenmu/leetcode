class Solution {
protected:

    bool isValidCoordinate(int r, int c, int row, int col) {
        return r >= 0 && c >= 0 && r < row && c < col;
    }

    void bfs(vector<vector<int>>& rooms, int r, int c) {

        int row = rooms.size();
        int col = rooms[0].size();

        queue<pair<pair<int, int>, int>> Q;
        Q.push(make_pair(make_pair(r, c), 0));
        
        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {-1, 1, 0, 0};
        
        while (!Q.empty()) {
            int cr = Q.front().first.first;
            int cc = Q.front().first.second;
            int dist = Q.front().second;
            Q.pop();
            
            if (rooms[cr][cc] == -1) {
                continue;
            }
            
            if (dist > rooms[cr][cc]) {
                continue;
            }
            
            rooms[cr][cc] = dist;
            
            for (int i = 0; i < 4; ++i) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                if (isValidCoordinate(nr, nc, row, col)) {
                    Q.push(make_pair(make_pair(nr, nc), dist + 1));
                }
            }
        }
    }
    
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0) {
            return;
        }

        int row = rooms.size();
        int col = rooms[0].size();

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (rooms[i][j] == 0) {
                    bfs(rooms, i, j);
                }
            }
        }
    }
};