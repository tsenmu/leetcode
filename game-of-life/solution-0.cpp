class Solution {
public:
    /**
     * Determines whether the index (r, c) is within the bounds of board.
     */
    bool is_valid(int r, int c, const vector<vector<int>>& board) {
        return (r >= 0 && r < board.size() && c >= 0 && c < board[0].size());
    }

    /**
     * Determines whether this value v has been encoded, i.e., the leftmost bit is 1.
     */
    bool is_encoded(int v) {
        return ((v & (1 << 31)) != 0);
    }

    /**
     * Gets the original state (1 or 1), i.e., the rightmost bit.
     */
    int get_original_state(int v) {
        return (v & 1); 
    }

    /**
     * Gets the number of alive neighbours from an encoded value v.
     */
    int get_neighbour_count(int v) {
        return ((v & (0xf << 1)) >> 1);
    }

    /**
     * Encodes the value at (r, c) on the board with 
     *   - original bit (rightmost bit)
     *   - alive neighbour count (2nd to 5th to the rightmost bits)
     *   - flag of encoding (leftmost bit)
     * Returns the encoded value.
     */
    int encode(int r, int c, const vector<vector<int>>& board) {
        int count = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int rr = i + r;
                int cc = j + c;
                if (is_valid(rr, cc, board)) {
                    int v = board[rr][cc];
                    if (is_encoded(v)) {
                        v = get_original_state(v);
                    }
                    count += v;
                }
            } 
        }
        return ((1 << 31) | (count << 1) | board[r][c]);
    }

    /**
     * Decodes the encoded value at (r, c) on the board.
     * Returns an integer of the new state of (r, c).
     */
    int decode(int r, int c, const vector<vector<int>>& board) {
        assert(is_valid(r, c, board));
        assert(is_encoded(board[r][c]));

        int original_state = get_original_state(board[r][c]);
        int count = get_neighbour_count(board[r][c]);
        if (original_state == 1) {
            if (count < 2) {
                return 0;
            } else if (count < 4) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (count == 3) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    /**
     * Transforms the board to the next state.
     */
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0) {
            return;
        } 

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                board[i][j] = encode(i, j, board);
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                board[i][j] = decode(i, j, board);
            }
        }
    }
};