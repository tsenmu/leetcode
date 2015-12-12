class Solution {
public:

    bool is_valid_coordinate(vector<vector<char>>& board, int r, int c) {
        if (board.size() == 0) {
            return false;
        }
        return r >= 0 && c >= 0 && r < board.size() && c < board[0].size();
    }

    void bfs(vector<vector<char>>& board, int r, int c) {
        vector<pair<int, int>> coordinate_list;
        queue<pair<int, int>> bfs_queue;

        coordinate_list.push_back(make_pair(r, c));
        bfs_queue.push(make_pair(r, c));
        board[r][c] = 'X';

        int r_deltas[] = {-1, 1, 0, 0};
        int c_deltas[] = {0, 0, -1, 1};

        bool is_captured = true;

        while (!bfs_queue.empty()) {
            pair<int, int> coordinate = bfs_queue.front();
            bfs_queue.pop();

            r = coordinate.first;
            c = coordinate.second;
            
            for (int i = 0; i < 4; ++i) {
                int current_r = r_deltas[i] + r;
                int current_c = c_deltas[i] + c;
                if (is_valid_coordinate(board, current_r, current_c)) {
                    if (board[current_r][current_c] == 'O') {
                        coordinate_list.push_back(make_pair(current_r, current_c));
                        bfs_queue.push(make_pair(current_r, current_c));
                        board[current_r][current_c] = 'X';
                    } 
                } else {
                    is_captured = false;
                }
            } 
        }

        if (!is_captured) {
            for (int i = 0; i < coordinate_list.size(); ++i) {
                r = coordinate_list[i].first; 
                c = coordinate_list[i].second;
                board[r][c] = 'V';
            }
        }

    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = 0;

        if (row == 0) {
            return;
        }

        col = board[0].size();

        // Notations:
        // X  - See specifications
        // O  - See specifications
        // V  - O that is verified not to be captured. 
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'O') {
                    bfs(board, i, j);
                } 
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'V') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};