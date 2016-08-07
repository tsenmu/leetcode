class SnakeGame {
protected:
    unordered_map<int, unordered_map<int, int>> m_board;
    queue<pair<int, int>> m_food;
    int m_score;
    int m_row;
    int m_col;
    list<pair<int,int>> m_list;

    bool isValidCoordinate(int r, int c) {
        return r >= 0 && c >= 0 && r < m_row && c < m_col;
    }

    bool hasFood(int r, int c) {
        return m_board[r][c] == 2;
    }

    bool isMovable(int r, int c) {
        return isValidCoordinate(r, c) && (m_board[r][c] != 1 || m_list.back().first == r && m_list.back().second == c);
    }

    void moveTo(int r, int c) {
        if (!isValidCoordinate(r, c)) {
            return;
        }

        m_list.push_front(make_pair(r, c));
        

        if (hasFood(r, c)) {
            m_score++;
            if (!m_food.empty()) {
                m_food.pop();
            }
            if (!m_food.empty()) {
                m_board[m_food.front().first][m_food.front().second] = 2;
            }
        } else {
            m_board[m_list.back().first].erase(m_list.back().second);
            if (m_board[m_list.back().first].size() == 0) {
                m_board.erase(m_list.back().first);
            }
            m_list.pop_back();
        }
        m_board[r][c] = 1;
    }


public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        m_row = height;
        m_col = width;

        m_board[0][0] = 1;
        for (pair<int, int>& f : food) {
            m_food.push(f);
        } 
        if (!m_food.empty()) {
            m_board[m_food.front().first][m_food.front().second] = 2;
        }
        m_score = 0;
        m_list.push_front(make_pair(0, 0));
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {

        int dr = 0;
        int dc = 0;

        switch (direction[0]) {
        case 'U':
            dr = -1;
            break;
        case 'L':
            dc = -1;
            break;
        case 'R':
            dc = 1;
            break;
        case 'D':
            dr = 1;
            break;
        }

        int nr = m_list.front().first + dr;
        int nc = m_list.front().second + dc;

        if (isMovable(nr, nc)) {
            moveTo(nr, nc);
        } else {
            return -1;
        }

        return m_score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */